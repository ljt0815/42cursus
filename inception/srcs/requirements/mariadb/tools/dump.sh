#!/bin/bash
mysqldump -uroot -pjitlee123 --all-databases > /dbdata/my.sql
echo "flush privileges;" >> /dbdata/my.sql
