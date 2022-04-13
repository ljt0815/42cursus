FROM debian:buster
RUN	apt-get update
RUN apt-get -y install nginx curl vim
RUN rm /etc/nginx/sites-available/default
COPY ./conf/default /etc/nginx/sites-available/default

CMD ["nginx", "-g", "daemon off;"]
