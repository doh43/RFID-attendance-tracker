# Stage 3

A temporary graphical user interface (GUI) with interactive buttons has been implemented to simulate RFID scanning and the retrieval of information from a MySQL database. This setup is in place while we continue configuring the necessary hardware for the Raspberry Pi.

# Setting up Docker

## Create a Docker Network

`docker network create qt-mysql`

## Create MYSQL Instance

`cd sql` \
`docker build -t mysqlgroup10 .`\
`docker run --name mysqlgroup10 --network qt-mysql mysqlgroup10`

## Create QTApp

Be in the group10 dir\
`docker build -t group10/app .`

`cd wsl`

Executes a .yml file that runs the application and sets up the GUI (mac X11 and WSL friendly)\
`docker compose up`

Alternatively for mac users:\
Create X11 server by following https://gist.github.com/sorny/969fe55d85c9b0035b0109a31cbcb088 then run\
`docker run -e DISPLAY=docker.for.mac.host.internal:0 --network qt-mysql group10/app`
## Errors

If you see this:
Error response from daemon: Conflict. The container name "/appgroup10" is already in use by container "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX". You have to remove (or rename) that container to be able to reuse that name.
Run
`docker rm XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX`

# Populating Database for Testing

Please execute the `create_database.sql` script located in the `./sql` directory within your MySQL database to populate it with sample data.
