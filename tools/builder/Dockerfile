FROM ubuntu:16.04

ENV HOME=/root
WORKDIR ${HOME}

RUN apt-get update \
    && apt-get -y install \
        unzip curl man \
        cmake=3.5.1-1ubuntu3 \
        gcc=4:5.3.1-1ubuntu1 g++=4:5.3.1-1ubuntu1 \
        git-all build-essential libtool \
        pkg-config autotools-dev autoconf automake \
        uuid-dev libpcre3-dev valgrind \
        crossbuild-essential-armhf

ENV TOOLS_PATH="${HOME}/tools"
ENV TOOLCHAINS_PATH="${TOOLS_PATH}/toolchains"
ENV CMAKE_TOOLCHAINS_PATH="${TOOLCHAINS_PATH}/toolchains-cmake-files"

COPY tools/ ${TOOLS_PATH}

RUN mkdir src/ deps/
