#!/bin/bash

if ! [[ mysql -u root -e "use $MYSQL_DB" ]]
then
mysql_install_db
mysql start

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
mysql stop
sleep 3
fi

mysqld
