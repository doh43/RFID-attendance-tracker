#!/bin/bash
# Sets up the application

# Change directory to the script's directory
cd "$(dirname "$0")"

cd ..

# If no command-line arguments are given, it will build the database image 
if [ $# -eq 0 ]; then
    echo "Building the application image..."
    docker build -t group10/app .

# Skips the build step if the -sb command-line argument is provided
elif [ "$1" = "-sb" ]; then
    echo "Skipping the build step"

# Error handling
else
    echo "Invalid argument: $1. Check README for correct use."
    exit 1
fi

cd wsl

# Runs the application image
echo "Running the application image..."
docker compose up

exit 0