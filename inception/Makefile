NAME = inception

all: clean start

domain:
	echo "127.0.0.1 jitlee.42.fr" >> /etc/hosts

start:
	docker-compose -f srcs/docker-compose.yml up -d

stop:
	docker exec -i mariadb /dump.sh
	docker-compose -f srcs/docker-compose.yml down

clean:
	docker-compose -f srcs/docker-compose.yml down --rm all -v

.PHONY: domain start stop clean
