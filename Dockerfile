FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    git \
    cmake \
    make \
    g++ \
    && apt-get clean