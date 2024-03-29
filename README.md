# Application Setup Instructions

## Step 0: Downloading Docker

This application uses Docker to ensure cross-platform compatibility. 
If you do not have it, it can be downloaded from Docker's official website: https://www.docker.com/

## Step 1: Create a Docker Network

`docker network create qt-mysql`

## Step 1.5: Automated Image Setup 

The bin directory contains some shell scripts that automate the setups for the next two steps. However, they are only compatible with UNIX-based Operating Systems (Linux and MacOS) due to their use of the bash shell and UNIX directory syntax.

### Setting permissions

From the **group10** directory:
`chmod +x bin/script_setup.sh` allows you to execute this script
`./bin/script_setup.sh` allows you to execute all scripts in bin

## Step 2: Set Up the MYSQL Database

### Automatic Method

In a bash terminal (in the group10 directory):
`./bin/db_setup.sh` sets up the database's Docker image. The `-sb` command-line argument can be added to skip the build step
**Note:** The script can be called from directories other than group10

### Manual Method

From the **group10** directory:
`cd sql` 
`docker build -t mysqlgroup10 .`
`docker run --name mysqlgroup10 --network qt-mysql mysqlgroup10`

## Step 3: Set Up the Qt App

### Automatic Method

In another bash terminal (in the group10 directory):
`./bin/app_setup.sh` sets up the app's Docker image. The `-sb` command-line argument can be added to skip the build step
**Note:** The script can be called from directories other than group10

### Manual Method

From the **group10** directory:
`docker build -t group10/app .`

#### For Linux users:

`cd wsl`
`docker compose up` Executes a .yml file that runs the application and sets up the GUI (mac X11 and WSL friendly)

#### For Mac users:

Create X11 server by following https://gist.github.com/sorny/969fe55d85c9b0035b0109a31cbcb088 then run:
`docker run -e DISPLAY=docker.for.mac.host.internal:0 --network qt-mysql group10/app`

## Step 4: Closing Docker Containers and Images

After you are done using the program, go into Docker Desktop and do the following:
- Go into the **Containers** tab
- Press the stop button for the mysqlgroup10 and wsl containers (in Actions)
    - The wsl container may not need to be stopped if the application windows were closed

To remove unused, dangling images run `docker image prune` from a bash terminal

## Errors

If you see this:
Error response from daemon: Conflict. The container name "/containername" is already in use by container "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX". You have to remove (or rename) that container to be able to reuse that name.
Run
`docker rm XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX`

## Populating Database for Testing
Please execute the `create_database.sql` script located in the `./sql` directory within your MySQL database to populate it with sample data.
