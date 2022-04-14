#!/bin/bash
sed "s/WP_USER_ID/${WP_USER_ID}/g" /setting.sql > /tmp1
sed "s/WP_USER_PW/${WP_USER_PW}/g" /tmp1 > /tmp2
sed "s/WP_ADMIN_PW/${WP_ADMIN_PW}/g" /tmp2 > /tmp3
sed "s/WP_ADMIN_ID/${WP_ADMIN_ID}/g" /tmp3 > /tmp4
sed "s/MY_DB_NAME/${MY_DB_NAME}/g" /tmp4 > /tmp5
sed "s/MY_DB_USER/${MY_DB_USER}/g" /tmp5 > /tmp6
sed "s/MY_DB_PWD/${MY_DB_PWD}/g" /tmp6 > /realsetting.sql
rm /tmp1 /tmp2 /tmp3 /tmp4 /tmp5 /tmp6
sleep 5s
if [ -e /dbdata/my.sql ]; then
	mysql < /dbdata/my.sql
else
	mysql < /realsetting.sql
fi
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY 'jitlee123';" | mysql
echo "restore success" > /aa
