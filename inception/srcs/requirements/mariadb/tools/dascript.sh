#!/bin/bash

RESULT=$(mysql -u root -e "use $MYSQL_DB")

if [[ -z "$RESULT" ]]
then
mysql_install_db
/etc/init.d/mysql start

mysql_secure_installation << EOF

y
$MYSQL_ROOT_PASSWORD
$MYSQL_ROOT_PASSWORD
y
n
y
y
EOF

< /tableup.scripture mysql -u root
sleep 3
/etc/init.d/mysql stop
sleep 3
fi

mysqld
