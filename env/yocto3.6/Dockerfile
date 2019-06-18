FROM ubuntu:16.04
WORKDIR /root/
RUN set -x && \
  apt-get update && \
  DEBIAN_FRONTEND=noninteractive apt-get install -y \
  cmake \
  subversion \
  smbclient \
  gawk \
  wget \
  git \
  language-pack-ja \
  diffstat \
  texinfo \
  gcc-multilib \
  build-essential \
  chrpath \
  socat \
  libsdl1.2-dev \
  xterm \
  python-crypto \
  cpio \
  python \
  python3 \
  python3-pip \
  python3-pexpect \
  libncurses5-dev \
  libncursesw5-dev \ 
  libc6-dev-i386 \
  p7zip-full \
  gettext \
  libexpat1-dev \
  libxml2-utils \
  libxml-xpath-perl \
  tar \
  bsdmainutils \
  zip \
  unzip \
  g++ \
  pkg-config \
  libasound2-dev \
  zlib1g-dev \
  xz-utils \
  debianutils \
  iputils-ping \
  libssl-dev \
  gdb \
  curl \
  apt-transport-https \
  genisoimage
RUN wget https://cmake.org/files/v3.8/cmake-3.8.0-rc2-Linux-x86_64.sh \
 && chmod +x ./cmake-3.8.0-rc2-Linux-x86_64.sh \
 && ./cmake-3.8.0-rc2-Linux-x86_64.sh --skip-license --prefix=/usr/local/ \
 && rm -f ./cmake-3.8.0-rc2-Linux-x86_64.sh
ENV LANG ja_JP.UTF-8
