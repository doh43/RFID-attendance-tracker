FROM biarms/mysql

ENV MYSQL_ROOT_PASSWORD=root

COPY ./create_database.sql /docker-entrypoint-initdb.d/
