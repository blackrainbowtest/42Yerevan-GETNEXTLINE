#!/bin/bash

make re
echo "Running tests..."

BUFFER_SIZES=(0 1 10 9999 10000000)

for BS in "${BUFFER_SIZES[@]}"; do
    echo "Testing with BUFFER_SIZE=${BS}..."
    gcc -D BUFFER_SIZE=${BS} get_next_line.c get_next_line_utils.c main.c -o gnl_test
    valgrind --leak-check=full ./gnl_test test.txt > result.txt 2>&1
    if grep -q "definitely lost: 0 bytes" result.txt; then
        echo -e "[BUFFER_SIZE=${BS}] \033[32m[OK]\033[0m"
    else
        echo -e "[BUFFER_SIZE=${BS}] \033[31m[KO]\033[0m"
    fi
done

rm -f gnl_test result.txt