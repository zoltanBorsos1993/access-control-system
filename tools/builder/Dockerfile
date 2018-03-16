FROM ubuntu:16.04

ENV HOME=/root
WORKDIR ${HOME}

RUN apt-get update \
    && apt-get -y install \
        unzip \
        cmake=3.5.1-1ubuntu3 \
        gcc=4:5.3.1-1ubuntu1 g++=4:5.3.1-1ubuntu1 \
        git-all build-essential libtool \
        pkg-config autotools-dev autoconf automake \
        uuid-dev libpcre3-dev valgrind

ENV TOOLS_PATH="${HOME}/tools"
ENV TOOLCHAINS_PATH="${TOOLS_PATH}/toolchains"
ENV CMAKE_TOOLCHAINS_PATH="${TOOLCHAINS_PATH}/toolchains-cmake-files"

COPY tools/ ${TOOLS_PATH}

ENV RPI_TOOLS_COMMIT_SHA=5caa7046982f0539cf5380f94da04b31129ed521
ADD https://github.com/raspberrypi/tools/archive/${RPI_TOOLS_COMMIT_SHA}.zip ${TOOLCHAINS_PATH}/rpi-tools.zip
# COPY tools-${RPI_TOOLS_COMMIT_SHA}.zip ${TOOLCHAINS_PATH}/rpi-tools.zip
RUN cd ${TOOLCHAINS_PATH} && unzip rpi-tools.zip && mv tools-${RPI_TOOLS_COMMIT_SHA} rpi-tools && rm rpi-tools.zip

RUN mkdir ${HOME}/sources/

ONBUILD ARG TARGET_ENVIRONMENT

ONBUILD COPY . sources/

ONBUILD RUN cd $(mktemp -d) \
          && cp -r ${HOME}/sources/* . \
          && ${TOOLS_PATH}/build-app ${TARGET_ENVIRONMENT}
