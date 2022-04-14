#!/bin/bash
sleep 5s
if [ -e /dbdata/my.sql ]; then
	mysql < /dbdata/my.sql
fi
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY 'jitlee123';" | mysql
echo "restore success" > /aa
