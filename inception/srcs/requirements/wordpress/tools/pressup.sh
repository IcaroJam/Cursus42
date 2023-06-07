#!/bin/bash

if ! [[ -f /var/www/wordpress/wp-config.php ]]
then
	curl -o /temp.phar https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x /temp.phar
	mv /temp.phar /usr/local/bin/wp

	wp core download --path=/var/www/wordpress --allow-root

	cp /var/www/wordpress/wp-config-sample.php /var/www/wordpress/wp-config.php
	sed -i "s/password_here/$MYSQL_PASSWORD/g" /var/www/wordpress/wp-config.php
	sed -i "s/localhost/mariadb.inception_incepnet/g" /var/www/wordpress/wp-config.php
	sed -i "s/username_here/$MYSQL_USER/g" /var/www/wordpress/wp-config.php
	sed -i "s/database_name_here/$MYSQL_DB/g" /var/www/wordpress/wp-config.php

	wp core install --allow-root --url=$DOMAIN_NAME --title=$WP_NAME \
		--admin_user=$WP_ROOT_USER --admin_password=$WP_ROOT_PASSWORD \
		--admin_email=$WP_ROOT_EMAIL --path=/var/www/wordpress

	wp user create $MYSQL_USER $WP_USER_EMAIL --user_pass=$MYSQL_PASSWORD \
		--role=author --allow-root --path=/var/www/wordpress
fi

mkdir -p /run/php
chown -R wpuser /var/www/wordpress && chmod -R 775 /var/www/wordpress

php-fpm7.3 -y /etc/php/7.3/fpm/php-fpm.conf -F
