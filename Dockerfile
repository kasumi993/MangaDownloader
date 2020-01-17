FROM ubuntu:latest 
RUN apt-get update && apt install wget -y
ENV ARGUMENTS manga
WORKDIR /home/manga
CMD ./downloader $ARGUMENTS