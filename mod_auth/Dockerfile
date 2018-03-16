ARG TARGET_ENVIRONMENT
ARG TARGET_IMAGE

# Builder
FROM monty-builder

RUN cd $(mktemp -d) \
      && curl -L -o zmq.zip https://github.com/zeromq/libzmq/archive/v4.2.3.zip \
      && unzip zmq.zip \
      && cd libzmq-4.2.3 \
      && ./autogen.sh \
      && ./configure \
      && make install \
      && ldconfig

RUN cd $(mktemp -d) \
      && curl -L -o czmq.zip https://github.com/zeromq/czmq/archive/v4.1.0.zip \
      && unzip czmq.zip \
      && cd czmq-4.1.0 \
      && ./autogen.sh \
      && ./configure \
      && make install \
      && ldconfig

# Application
FROM ${TARGET_IMAGE}

COPY --from=0 /root/bin app/

CMD ./app/mod_auth.run
