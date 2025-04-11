 
#author Umar Ba <jUmarB@protonmail.com> 

FROM jukoo/voidlinux:generic 
MAINTAINER Umar Ba <jUmarB@protonmail.com> 


ENV TERM=xterm
ENV XTERM_256_COLORS=1

RUN  xbps-install -Sy && xbps-install -yu xbps 
RUN  xbps-install -y  gcc  cmake git  openssl ncurses ncurses-devel ncurses-base ncurses-libs 

WORKDIR  /ftp-FM 

ADD  ./  ./  


 
RUN  cmake -B build  &&  cmake --build build  


EXPOSE 9090 


CMD  ["./bin/ftpFM"]
