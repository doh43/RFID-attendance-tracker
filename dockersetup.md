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
`docker run -e DISPLAY=docker.for.mac.host.internal:0 --network qt-mysql group10/app`


## Errors
If you see this: 
Error response from daemon: Conflict. The container name "/appgroup10" is already in use by container "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX". You have to remove (or rename) that container to be able to reuse that name.
Run
`docker rm XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX`