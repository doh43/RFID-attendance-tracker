# Setup Instructions for RC522 RFID Reader on Raspberry Pi
## Step 1: Install the Latest Versions
1. `sudo apt-get update` & `sudo apt-get upgrade` & `raspi-update`  
2. Make sure you have SPI in raspi-config (inside Interfacing Options) 
3. Make sure that Device tree is enabled in raspi config (advanced section) 

## Step 2: BCM2835 Library Installation
Install the latest version from BCM2835 from : http://www.airspayce.com/mikem/bcm2835/ 
1. wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.56.tar.gz 
2. tar -zxf bcm2835-1.56.tar.gz 
3. cd bcm2835-1.56 
4. ./configure 
5. sudo make check 
6. sudo make install 
7. cd  .. 

# Application Setup Instructions

## Step 0: Downloading Docker

This application uses Docker to ensure cross-platform compatibility.
If you do not have it, it can be downloaded from Docker's official website: https://www.docker.com/

## Step 1: Create a Docker Network

`docker network create qt-mysql`

## Step 1.5: Automated Image Setup

The bin directory contains some shell scripts that automate the setups for the next two steps. However, they are only compatible with UNIX-based Operating Systems (Linux and MacOS) due to their use of the bash shell and UNIX directory syntax.

### Setting permissions

From the **group10** directory: \
`chmod +x bin/script_setup.sh` allows you to execute this script 
`./bin/script_setup.sh` allows you to execute all scripts in bin

## Step 2: Set Up the MYSQL Database

### Automatic Method

In a bash terminal (in the group10 directory): \
`./bin/db_setup.sh` sets up the database's Docker image. The `-sb` command-line argument can be added to skip the build step \
**Note:** The script can be called from directories other than group10

### Manual Method

From the **group10** directory:
`cd sql` \
`docker build -t mysqlgroup10 .` \
`docker run --name mysqlgroup10 --network qt-mysql -p 3307:3306 mysqlgroup10` 

## Step 3: Set Up the Qt App

### Automatic Method

In another bash terminal (in the group10 directory): \
`./bin/app_setup.sh` sets up the app's Docker image. The `-sb` command-line argument can be added to skip the build step \
**Note:** The script can be called from directories other than group10

### Manual Method

From the **group10** directory:
`docker build -t group10/app .`

#### For Linux users:

`cd wsl` \
`docker compose up` Executes a .yml file that runs the application and sets up the GUI (mac X11 and WSL friendly) 

#### For Mac users:

Create X11 server by following https://gist.github.com/sorny/969fe55d85c9b0035b0109a31cbcb088 then run: 
`docker run -e DISPLAY=docker.for.mac.host.internal:0 --network qt-mysql group10/app` 

#### For Raspberry Pi:

`docker run -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --network qt-mysql group10/app` 

## Step 4: Running the RFID Scanner
Program `read.cpp` will read RFID cards and log them inside a MySQL database. 
Navigate to the `backend` folder and run  `g++ MFRC522.cpp read.cpp -std=c++11 -lbcm2835 -lmysqlcppconn`.  Run `sudo ./a.out` to start the scanner. 

## Step 5: Closing Docker Containers and Images

After you are done using the program, go into Docker Desktop and do the following:

- Go into the **Containers** tab
- Press the stop button for the mysqlgroup10 and wsl containers (in Actions)
  - The wsl container may not need to be stopped if the application windows were closed

To remove unused, dangling images, run `docker image prune` from a bash terminal 

## Opening a Shell Session

Run `docker exec -it [container id] sh` to open an interactive shell session inside the specified running container. This is particularly useful for debugging, modifying configuration files, inspecting the container's environment, or any other task that requires direct command-line access to the container's internal environment.

## Errors

If you see this:
Error response from daemon: Conflict. The container name "/containername" is already in use by container "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX". You have to remove (or rename) that container to be able to reuse that name. \
Run
`docker rm XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX`

