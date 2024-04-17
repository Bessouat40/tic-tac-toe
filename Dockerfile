FROM ubuntu:latest

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y \
    g++ git wget cmake sudo

# RUN apt-get install -y \
#     build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev \
#     python3-dev python3-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev \
#     libcanberra-gtk-module libcanberra-gtk3-module

# RUN git clone https://github.com/opencv/opencv.git && \
#     cd /opencv && mkdir build && cd build && \
#     cmake -D CMAKE_BUILD_TYPE=Release -D    CMAKE_INSTALL_PREFIX=/usr/local .. && \
#     make -j"$(nproc)" && \
#     make install  && ldconfig

COPY src /app/src
COPY main.cpp /app/

WORKDIR /app/

RUN echo "export DISPLAY=:0.0" >> ~/.bashrc

RUN g++ -std=c++17 -o test main.cpp src/*.cpp
CMD ["./test"]