ARG TARGET_ENVIRONMENT
ARG TARGET_IMAGE

# Builder
FROM monty-builder

# Application
FROM ${TARGET_IMAGE}

COPY --from=0 /root/bin app/

CMD ./app/mod_comm.run
