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

ENV CPPZMQ_VERSION="v4.2.3"
ENV CPPZMQ_PREFIX="${HOME}/deps/usr/local"
RUN cd $(mktemp -d) \
      && git clone https://github.com/zeromq/cppzmq.git \
      && cd cppzmq \
      && git checkout ${CPPZMQ_VERSION} \
      && cp zmq.hpp zmq_addon.hpp ${CPPZMQ_PREFIX}/include/

ENV JSON_PARSER_VERSION="v3.1.1"
ENV JSON_PARSER_PREFIX="${HOME}/deps/usr/local"
RUN cd $(mktemp -d) \
      && git clone https://github.com/nlohmann/json.git \
      && cd json \
      && git checkout ${JSON_PARSER_VERSION} \
      && cp -r include ${JSON_PARSER_PREFIX}/
ENV PKG_CONFIG_PATH="${PKG_CONFIG_PATH}:${CZMQ_PREFIX}/lib/pkgconfig"

# Building app
COPY . src/

ARG TARGET_ENVIRONMENT

RUN cd $(mktemp -d) \
      && cp -r ${HOME}/src/* . \
      && mv $(find -name 'CMakeList*') CMakeLists.txt \
      && ${TOOLS_PATH}/build-app ${TARGET_ENVIRONMENT}

# Application
FROM ${TARGET_IMAGE}

COPY --from=0 /root/bin bin/
COPY --from=0 /root/deps deps/

CMD ${TOOLS_PATH}/register-libs \
      && echo "Starting module 'auth'..." \
      && ./bin/mod_auth.run
