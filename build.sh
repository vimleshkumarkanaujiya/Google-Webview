#!/bin/bash

OUTPUT_FILE="Google"
SOURCE_FILE="main.cpp"

pkg-config --cflags --libs gtk+-3.0 webkit2gtk-4.0 > flags.txt
g++ -o $OUTPUT_FILE $SOURCE_FILE $(<flags.txt)
rm flags.txt

echo "Compilation complete. Executable file: $OUTPUT_FILE"
