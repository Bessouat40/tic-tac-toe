FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y \
    g++ git wget cmake sudo

COPY src /app/src
COPY main.cpp /app/

WORKDIR /app/

RUN echo "export DISPLAY=:0.0" >> ~/.bashrc

RUN g++ -std=c++17 -o test main.cpp src/*.cpp
CMD ["./test"]