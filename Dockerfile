FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    git \
    cmake \
    make \
    g++-13 \
    && apt-get clean