FROM ilkou/minilibx:ubuntu

RUN apt-get update 
Run apt-get -y upgrade 
RUN DEBIAN_FRONTEND=noninteractive apt-get install -f -y git build-essential clang valgrind

WORKDIR /home
