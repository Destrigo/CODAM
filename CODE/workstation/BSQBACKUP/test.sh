#!/bin/bash

program="bsq"
valgrind="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes"
directory="files/random"

mkdir -p ${directory}

while true; do
    width=$(((RANDOM % 1000) + 1))
    height=$(((RANDOM % 1000) + 1))
    density=$(((RANDOM % 50) + 1))
    filename="${directory}/${width}-${height}-${density}"
    ./generate_map.pl ${width} ${height} ${density} >${filename}

    echo "${filename}: solving..."

    SECONDS=0
    ./${program} ${filename} 1>${filename}.solution ||
        echo "ERROR: look at ${filename} and ${filename}.solution"

    echo "${filename}: solved in ${SECONDS} seconds (argument)"

    SECONDS=0
    ${valgrind} ./${program} <$filename 1>${filename}.solution 2>${filename}.valgrind ||
        echo "ERROR: look at ${filename}, ${filename}.solution, and ${filename}.valgrind"

    echo "${filename}: solved in ${SECONDS} seconds (stdin with valgrind)"
done
