#!/bin/bash
echo
echo
echo "Testing varargs.c........."
echo "Expected: Out of bounds error"
echo
echo "Actual Result:"
clang -o varargs -fsanitize=address -fno-omit-frame-pointer -g varargs.c && ./varargs
echo "varargs.c..... Done"
echo
echo
echo "------------------------------------------------------------------------------------------------------------"
echo "Testing sscanf.c........."
echo "Expected: No error or warning"
echo
echo "Actual Result:"
clang -o sscanf -fsanitize=memory -fsanitize-memory-track-origins -g sscanf.c && ./sscanf
echo "sscanf.c..... Done"
echo
echo
echo "------------------------------------------------------------------------------------------------------------"
echo "Testing aligned_alloc.c........."
echo "Expected: No error or warning"
echo
echo "Actual Result:"
gcc -std=c11 -o aligned_alloc -fsanitize=address -g aligned_alloc.c && ./aligned_alloc
echo "aligned_alloc.c..... Done"
echo
echo
echo "------------------------------------------------------------------------------------------------------------"
echo "Testing uninitialized_array.c........."
echo "Expected: Array out of bounds access warning or error"
echo
echo "Actual Result:"
clang -w -o uninitialized_array -fno-omit-frame-pointer -fno-common -g uninitialized_array.c && ./uninitialized_array
echo "uninitialized_array.c..... Done"
echo
echo
echo "------------------------------------------------------------------------------------------------------------"
echo "Testing argv-out-of-bound.c........."
echo "Expected: argv out of bounds warning"
echo
echo "Actual Result:"
clang -o argv-out-of-bound -fsanitize=address argv-out-of-bound.c && ./argv-out-of-bound
echo "argv-out-of-bound.c..... Done"
echo
echo
echo "------------------------------------------------------------------------------------------------------------"
echo "Testing copy_relocation.c........."
echo "Expected: Out of bounds error or warning"
echo
echo "Actual Result:"
gcc -fsanitize=address extern_array.c -shared -fpic -fsanitize=address -o extern_array.so
gcc -fsanitize=address copy_relocation.c -c -o copy_relocation.o
gcc -fsanitize=address copy_relocation.o ./extern_array.so -o copy_relocation
echo "copy_relocation.c..... Done"
echo 
echo
echo "------------------------------------------------------------------------------------------------------------"
echo "Testing semaphore.c........."
echo "Expected: Access after free error"
echo
echo "Actual Result:"
clang -o semaphore -fsanitize=address -pthread semaphore.c && ./semaphore
echo "semaphore.c..... Done"
echo
echo
echo "------------------------------------------------------------------------------------------------------------"
echo "Testing tsan_false-positive.cpp........."
echo "Expected: "
echo "Inside func"
echo "Inside func"
echo
echo "Actual Result:"
g++ -o tsan_false-positive -O3 -g3 -fsanitize=thread -pie -fPIE -Wall -std=c++11 -pthread -Wextra tsan_false-positive.cpp && ./tsan_false-positive
echo "tsan_false-positive.cpp..... Done"
echo
echo
echo "------------------------------------------------------------------------------------------------------------"
echo "Testing fno-common.c........."
echo "Expected: Out of bounds access error"
echo
echo "Actual Result:"
clang -o fno-common -fsanitize=address fno-common.c && ./fno-common
echo "fno-common.c..... Done"
echo
echo
echo "------------------------------------------------------------------------------------------------------------"
echo "Testing compile-time-undefined.c with -O0........."
echo "Expected: Use of uninitialized value warning"
echo
echo "Actual Result:"
clang -o compile-time-undefined -fsanitize=memory -O0 compile-time-undefined.c && ./compile-time-undefined
echo
echo "Testing compile-time-undefined.c with -O1........."
echo "Expected: Use of uninitialized value warning"
echo
echo "Actual Result:"
clang -o compile-time-undefined -fsanitize=memory -O1 compile-time-undefined.c && ./compile-time-undefined
echo "compile-time-undefined.c..... Done"
echo
echo
echo "------------------------------------------------------------------------------------------------------------"
echo "Testing atomics-gcc.c........."
echo "Expected: No warning or error"
echo
echo "Actual Result:"
g++ -std=c++14 -o atomics-gcc -fsanitize=thread -pie -fPIE -g atomics-gcc.cpp -lpthread && ./atomics-gcc
echo "atomics-gcc.c..... Done"
