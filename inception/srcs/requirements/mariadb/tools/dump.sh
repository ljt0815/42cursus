#!/bin/bash
mysqldump -uroot -pjitlee123 --all-databases > /dbdata/my.sql
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY 'jitlee123';" >> /dbdata/my.sql
echo "FLUSH PRIVILEGES;" >> /dbdata/my.sql
