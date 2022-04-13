start:
	docker-compose -f srcs/docker-compose.yml up -d

stop:
	docker exec -i srcs_mariadb_1 /dump.sh
	docker-compose -f srcs/docker-compose.yml down

clean:
	docker-compose -f srcs/docker-compose.yml down --rm all -v
