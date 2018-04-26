FROM ubuntu:14.04
WORKDIR /root/
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y cmake subversion smbclient gawk wget git language-pack-ja diffstat texinfo gcc-multilib build-essential chrpath socat libsdl1.2-dev
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y xterm cpio libncurses5-dev libncursesw5-dev libc6-dev-i386 p7zip-full gettext libexpat1-dev libxml2-utils libxml-xpath-perl tar bsdmainutils
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y zip unzip g++ pkg-config libasound2-dev zlib1g-dev xz-utils gdb
RUN wget https://cmake.org/files/v3.8/cmake-3.8.0-rc2-Linux-x86_64.sh
RUN chmod +x ./cmake-3.8.0-rc2-Linux-x86_64.sh
RUN ./cmake-3.8.0-rc2-Linux-x86_64.sh --skip-license --prefix=/usr/local/
RUN rm -f ./cmake-3.8.0-rc2-Linux-x86_64.sh
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y curl apt-transport-https genisoimage
RUN curl https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > microsoft.gpg
RUN mv microsoft.gpg /etc/apt/trusted.gpg.d/microsoft.gpg
RUN sh -c 'echo "deb [arch=amd64] https://packages.microsoft.com/repos/microsoft-ubuntu-trusty-prod trusty main" > /etc/apt/sources.list.d/dotnetdev.list'
RUN cat /etc/apt/sources.list.d/dotnetdev.list
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y dotnet-runtime-2.0.5
RUN wget https://repo.continuum.io/miniconda/Miniconda3-latest-Linux-x86_64.sh
RUN chmod +x Miniconda3-latest-Linux-x86_64.sh
RUN ./Miniconda3-latest-Linux-x86_64.sh -b
RUN rm -f ./Miniconda3-latest-Linux-x86_64.sh
RUN echo '#export PATH="/root/miniconda3/bin:$PATH"' >> .bashrc
ENV LANG ja_JP.UTF-8
