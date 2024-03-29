#!/bin/bash
# Sets execute permissions for all shell files in bin

# Change directory to the script's directory
cd "$(dirname "$0")"

# Find all shell files and give them execute permissions
find . -type f -name "*.sh" -exec chmod +x {} \;

echo "Execute permissions added to all shell files in the directory."
exit 0