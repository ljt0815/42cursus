#!/bin/bash
mysqldump -uroot -pjitlee123 --all-databases > /dbdata/my.sql
"ALTER USER 'root'@'localhost' IDENTIFIED BY 'jitlee123';" >> /dbdata/my.sql
"FLUSH PRIVILEGES;" >> /dbdata/my.sql
