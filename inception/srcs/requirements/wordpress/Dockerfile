# Get the base image, in this case the oldest lts of debian os:
FROM	debian:buster

# Get that shit installed:
RUN		apt-get update && apt-get install -y php7.3-fpm php7.3-mysql php7.3-xml php7.3-curl php7.3-mbstring php7.3-zip

# Overwrite the default config:
COPY	./config/php-fpm.conf /etc/php/7/fpm/php-fpm.conf
# Put the script in the container and get those permissions permitted:
COPY	./tools/pressup.sh /pressup.sh
RUN		chmod +x /pressup.sh

EXPOSE	9000

CMD		["/pressup.sh"]
