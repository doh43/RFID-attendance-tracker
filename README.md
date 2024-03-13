# Setting up Docker

## Create a Docker Network

`docker network create qt-mysql`

## Create MYSQL Instance

`cd sql`
`docker build -t mysqlgroup10 .`
`docker run --name mysqlgroup10 --network qt-mysql mysqlgroup10`

## Create QTApp

Be in the group10 dir
`docker build -t group10/app .`

`cd wsl`

Executes a .yml file that runs the application and sets up the GUI (mac X11 and WSL friendly)
`docker compose up`

## Errors

If you see this:
Error response from daemon: Conflict. The container name "/appgroup10" is already in use by container "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX". You have to remove (or rename) that container to be able to reuse that name.
Run
`docker rm XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX`

# Populating Database for Testing

Paste the `create_database.sql` script found inside the `./sql` directory inside your MySQL database to populate it with placeholder data.
