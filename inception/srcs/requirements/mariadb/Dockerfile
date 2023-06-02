# Get the base image, in this case the oldest lts of debian os:
FROM	debian:buster

RUN		apt-get update && apt-get install -y mariadb-client mariadb-server

COPY	./config/sequel.conf /etc/mysql/my.cnf
COPY	./tools/dascript.sh /dascript.sh
RUN		chmod +x /dascript.sh && \
		echo "GRANT ALL ON *.* TO '$MYSQL_ROOT_USER'@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'; \
		FLUSH PRIVILEGES; \
		CREATE DATABASE IF NOT EXISTS $MYSQL_DB; \
		CREATE USER '$MYSQL_USER'@'wordpress.inception_incepnet' IDENTIFIED BY '$MYSQL_PASSWORD'; \
		GRANT ALL ON *.* TO '$MYSQL_USER'@'wordpress.inception_incepnet'; \
		FLUSH PRIVILEGES;" > /tableup.scripture

EXPOSE	3306

CMD		["/dascript.sh"]
