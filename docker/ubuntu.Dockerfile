FROM ubuntu:20.04 as BASE

RUN apt update && DEBIAN_FRONTEND=noninteractive apt install qt5-default cmake ninja-build

WORKDIR /home/qt5
