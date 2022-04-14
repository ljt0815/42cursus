FROM debian:buster
COPY ./conf/setting.sql /
RUN	apt-get update
RUN apt-get -y install mariadb-server
RUN rm /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./tools/inception /
COPY ./tools/dump.sh /
COPY ./tools/restore.sh /

ENTRYPOINT ["sh", "/inception"]
