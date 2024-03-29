#!/bin/bash
# Sets up the application's mysql database

# Change directory to the script's directory
cd "$(dirname "$0")"

cd ../sql

# If no command-line arguments are given, it will build the database image 
if [ $# -eq 0 ]; then
    echo "Building the database image..."
    docker build -t mysqlgroup10 .

# Skips the build step if the -sb command-line argument is provided
elif [ "$1" = "-sb" ]; then
    echo "Skipping the build step"

# Error handling
else
    echo "Invalid argument: $1. Check README for correct use."
    exit 1
fi

# Runs the database image
echo "Running the database image..."
docker run --name mysqlgroup10 --network qt-mysql mysqlgroup10

exit 0