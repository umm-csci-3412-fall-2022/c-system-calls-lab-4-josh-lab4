#!/bin/bash

# Take the directory that we are working out of as the only argument
Dir="$1"

# Find all directories in the given directory
# Count the number of directories
# Print out the number of directories
find "$Dir" -type d | wc -l | xargs printf "There were %i directories.\n"

# Find all files in the given directory
# Count the number of files
# Print out the number of files
find "$Dir" -type f | wc -l | xargs printf "There were %i regular files.\n"

# Note: Using printf, you need to tab to the next line, because it does not automatically do it for you
