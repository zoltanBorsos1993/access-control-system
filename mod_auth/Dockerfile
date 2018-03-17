ARG TARGET_IMAGE

# Builder
FROM monty-builder

# Dependecies
ENV ZMQ_VERSION="v4.2.3"
RUN cd $(mktemp -d) \
      && git clone https://github.com/zeromq/libzmq.git \
      && cd libzmq/ \
      && git checkout ${ZMQ_VERSION} \
      && ./autogen.sh \
      && ./configure --host arm-linux-gnueabihf \
      && make install \
      && ldconfig

ENV CZMQ_VERSION="v4.1.0"
RUN cd $(mktemp -d) \
      && git clone https://github.com/zeromq/czmq.git \
      && cd czmq/ \
      && git checkout ${CZMQ_VERSION} \
      && ./autogen.sh \
      && ./configure --host arm-linux-gnueabihf \
      && make install \
      && ldconfig

# Building app
COPY . app/

ARG TARGET_ENVIRONMENT

RUN cd $(mktemp -d) \
      && cp -r ${HOME}/app/* . \
      && ${TOOLS_PATH}/build-app ${TARGET_ENVIRONMENT}

# Application
FROM ${TARGET_IMAGE}

COPY --from=0 /root/bin app/

CMD ./app/mod_auth.run
