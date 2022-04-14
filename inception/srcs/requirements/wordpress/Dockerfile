FROM debian:buster
RUN		apt-get update
RUN		apt-get -y install php-fpm php7.3-xml php7.3-curl php7.3-gd php7.3-mbstring php7.3-readline php7.3-bz2 php7.3-zip php7.3-json php7.3-opcache php-mysql
RUN		rm -rf /etc/php/7.3/fpm/pool.d/www.conf
COPY	./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY	./tools/inception /inception
COPY	./tools/latest.tar.gz /
RUN		tar -xvf /latest.tar.gz
RUN		chown -R www-data:www-data /wordpress
COPY	./conf/wp-config.php /
RUN		mkdir /run/php

CMD ["sh", "/inception"]
