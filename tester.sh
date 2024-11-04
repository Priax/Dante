#!/bin/bash

set -euo pipefail

echo "Hello, welcome to our generator !"

if [ $# -lt 2 ] || [ $# -gt 3 ]; then
    echo ""
    echo "Error: Invalid number of arguments. Usage: $0 <arg1> <arg2> [arg3]"
    echo "Refer to README if needed."
    exit 1
fi

if ! command -v ./generator/generator &> /dev/null; then
    echo "Error: 'generator' command not found."
    exit 1
fi

if [ $# -eq 2 ]; then
    echo "Generating imperfect maze..."
    time ./generator/generator "$1" "$2" > "maps/maze.txt"; echo ""
else
    echo "Generating maze..."
    time ./generator/generator "$1" "$2" "$3" > "maps/maze.txt"; echo ""
fi

if ! command -v ./solver/solver &> /dev/null; then
    echo "Error: 'solver' command not found."
    exit 1
fi
# Black: \033[0;30m or \033[30m
# Red: \033[0;31m or \033[31m
# Green: \033[0;32m or \033[32m
# Yellow: \033[0;33m or \033[33m
# Blue: \033[0;34m or \033[34m
# Magenta: \033[0;35m or \033[35m
# Cyan: \033[0;36m or \033[36m
# White: \033[0;37m or \033[37m
echo "Solving maze..."; echo ""
time ./solver/solver "maps/maze.txt" | sed 's/o/\o033[32mo\o033[0m/g'; echo ""

echo "Maze generated !"
