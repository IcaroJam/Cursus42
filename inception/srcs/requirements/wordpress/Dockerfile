# Get the base image, in this case the oldest lts of debian os:
FROM	debian:buster

# Get that shit installed:
RUN		apt-get update && apt-get install -y \
		wget tar gettext php7-fpm php7-mysqli php7-json

# Overwrite the default config:
COPY	./config/php-fpm.conf /etc/php/7/fpm/php-fpm.conf
# Put the script in the container and get those permissions permitted:
COPY	./tools/pressup.sh /pressup.sh
RUN		chmod +x /pressup.sh

EXPOSE	9000

CMD		["/pressup.sh"]
