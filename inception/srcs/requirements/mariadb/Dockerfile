# Get the base image, in this case the oldest lts of debian os:
FROM	debian:buster

RUN		apt-get update -y && apt-get install -y mariadb-client mariadb-server

RUN		mkdir -p /var/run/mysqld && \
		chown -R mysql:mysql /var/run/mysqld && \
		chown 777 /var/run/mysqld

COPY	./config/sequel.conf /my.cnf
COPY	./tools/.env /.env
COPY	./tools/dascript.sh /dascript.sh

RUN		chmod +x /dascript.sh

EXPOSE	3306

RUN		export $(cat /.env | xargs) && \
		/dascript.sh

CMD		["mysqld"]
