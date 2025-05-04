#+ @file  Dockerfile
#  @author Umar Ba <jUmarB@protonmail.com> 

FROM  ghcr.io/void-linux/void-glibc-full:20250501r1
MAINTAINER Umar Ba <jUmarB@protonmail.com> 


#+  Needed by  curses 
ENV TERM=xterm
ENV XTERM_256_COLORS=1

RUN  xbps-install -Sy  && xbps-install -u  xbps 
RUN  xbps-install  meson git ncurse-devel  pkg-config 

WORKDIR  /ftp-FM 

ADD  ./  ./  

RUN  meson setup build && meson  compile -C build  


EXPOSE 9090 


CMD  ["./bin/ftpFM"]
