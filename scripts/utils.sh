#!/bin/bash
# Helper script for LeetCode C++ project

set -euo pipefail

# Configuration
SRCDIRS=("easy" "medium" "hard")

# Find source file (.cpp)
find_source() {
    local filename="$1"
    for dir in "${SRCDIRS[@]}"; do
        local src_path="$dir/$filename.cpp"
        if [ -f "$src_path" ]; then
            echo "$src_path"
            return 0
        fi
    done
    echo ""
    return 1
}

# Handle command
case "$1" in
    find_source)
        if [ $# -ne 2 ]; then
            echo "Usage: $0 find_source <filename>"
            exit 1
        fi
        find_source "$2"
        ;;
    *)
        echo "Unknown command: $1"
        exit 1
        ;;
esac
