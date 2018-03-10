FROM monty/builder
ARG TARGET_ENVIRONMENT

#  Read-only bind mounting source files to $HOME/sources.

COPY . sources/

RUN cd $(mktemp -d) \
    && cp -r ${HOME}/sources/* . \
    && ${TOOLS_PATH}/build-app ${TARGET_ENVIRONMENT}

# TODO: look for lightweight image.
FROM ubuntu:16.04
COPY --from=0 /root/bin app/

CMD ./app/mod_auth.run
