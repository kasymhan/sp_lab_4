FROM ubuntu:latest
ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update && \
    apt-get -y install gdb gcc g++ mono-mcs build-essential gcc-multilib g++-multilib libc6-dev-i386 && \
    rm -rf /var/lib/apt/lists/*
COPY . .
#RUN gcc -m32  -lc --entry main test2.c -o test2 -g
#RUN gcc -m32  -lc --entry main test1.c -o test1 -g
RUN g++ test2.cpp -o test2
RUN g++ test1.cpp -o test1
CMD  ./test1
#COPY ./Assembler/task_12_c.c ./
#COPY ./Ci/task_12_s.s ./
#COPY ./hello.s ./

