ARG TARGET_IMAGE

# Builder
FROM monty-builder
ARG TARGET_TRIPLET
ARG C_COMPILER
ARG CXX_COMPILER

# Dependecies
ENV ZMQ_VERSION="v4.2.3"
ENV ZMQ_PREFIX="${HOME}/deps/usr/local"
RUN cd $(mktemp -d) \
      && git clone https://github.com/zeromq/libzmq.git \
      && cd libzmq/ \
      && git checkout ${ZMQ_VERSION} \
      && ./autogen.sh \
      && ./configure --host="${TARGET_TRIPLET}" --build="x86_64-linux-gnu" --prefix="${ZMQ_PREFIX}" \
      && make install \
      && ldconfig
ENV PKG_CONFIG_PATH="${PKG_CONFIG_PATH}:${ZMQ_PREFIX}/lib/pkgconfig"

ENV CZMQ_VERSION="v4.1.0"
ENV CZMQ_PREFIX="${HOME}/deps/usr/local"
RUN cd $(mktemp -d) \
      && git clone https://github.com/zeromq/czmq.git \
      && cd czmq/ \
      && git checkout ${CZMQ_VERSION} \
      && ./autogen.sh \
      && CFLAGS="-I${ZMQ_PREFIX}/include" \
          LDFLAGS="-L${ZMQ_PREFIX}/lib" \
          PKG_CONFIG_PATH="${ZMQ_PREFIX}/lib/pkgconfig" \
            ./configure --host="${TARGET_TRIPLET}" --build="x86_64-linux-gnu" --prefix="${CZMQ_PREFIX}" \
      && make install \
      && ldconfig
ENV PKG_CONFIG_PATH="${PKG_CONFIG_PATH}:${CZMQ_PREFIX}/lib/pkgconfig"

ENV SQLITE_VERSION="3.22.0"
ENV SQLITE_PREFIX="${HOME}/deps/usr/local"
RUN cd $(mktemp -d) \
    && curl -o sqlite.zip "https://www.sqlite.org/2018/sqlite-amalgamation-3220000.zip" \
    && unzip sqlite \
    && mv sqlite-amalgamation-3220000 sqlite \
    && cd sqlite \
    && ${C_COMPILER} -o "${SQLITE_PREFIX}/lib/libsqlite3.so" -fPIC -Wall -Wl,-soname,libsqlite3.so sqlite3.c -shared \
    && cp sqlite3.h "${SQLITE_PREFIX}/include/"

# Building app
COPY . src/

ARG TARGET_ENVIRONMENT

RUN cd $(mktemp -d) \
      && cp -r ${HOME}/src/* . \
      && ${TOOLS_PATH}/build-app ${TARGET_ENVIRONMENT}

# Application
FROM ${TARGET_IMAGE}

COPY --from=0 /root/bin bin/
COPY --from=0 /root/deps deps/

CMD ${TOOLS_PATH}/register-libs \
      && echo "Starting module 'database'..." \
      && ./bin/mod_database.run
