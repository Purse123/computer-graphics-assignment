#! /usr/bin/bash

export C_INCLUDE_PATH="/usr/local/include/SDL3:$C_INCLUDE_PATH"
export LIBRARY_PATH="/usr/local/lib:$LIBRARY_PATH"

if [ $# -ne 2 ]; then
    echo "Usage: $0 <output_file> <source_file>"
    exit 1
fi

OBJECT_FILE="$1"
SOURCE_FILE="$2"

# gcc -o $OBJECT_FILE $SOURCE_FILE -I/usr/local/include/SDL3 -L/usr/local/lib -lSDL3
gcc -o "$OBJECT_FILE" "$SOURCE_FILE" -I"$C_INCLUDE_PATH" -L"$LIBRARY_PATH" -lSDL3

./"$OBJECT_FILE"
