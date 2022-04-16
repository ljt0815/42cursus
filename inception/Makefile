NAME = inception

all: clean start

domain:
	echo "127.0.0.1 jitlee.42.fr" >> /etc/hosts

volume:
	mkdir -p /home/jitlee/data/wpdata
	mkdir -p /home/jitlee/data/dbdata

start:
	docker-compose -f srcs/docker-compose.yml up -d

stop:
	docker exec -i mariadb /dump.sh
	docker-compose -f srcs/docker-compose.yml down

clean:
	docker-compose -f srcs/docker-compose.yml down --rm all -v

.PHONY: domain volume start stop clean
