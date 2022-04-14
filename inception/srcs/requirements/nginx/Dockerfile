FROM debian:buster
RUN	apt-get update
RUN apt-get -y install nginx curl vim
RUN rm /etc/nginx/sites-available/default
COPY ./conf/default /etc/nginx/sites-available/default
RUN mkdir -p /etc/nginx/ssl
COPY ./conf/test.key /etc/nginx/ssl/test.key
COPY ./conf/test.crt /etc/nginx/ssl/test.crt

CMD ["nginx", "-g", "daemon off;"]
