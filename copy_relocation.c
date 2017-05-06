/*

Usage: 
gcc -fsanitize=address extern_array.c -shared -fpic -fsanitize=address -o extern_array.so
gcc -fsanitize=address copy_relocation.c -c -o copy_relocation.o
gcc -fsanitize=address copy_relocation.o ./extern_array.so -o copy_relocation
./copy_relocation

*/
#include <stdio.h>
extern int arr[10];
int main ()
{
	printf("Testing ASAN with copy relocation");
	return arr[10];
}

/*Doesn't throw an error with address sanitizer. This is an intentional design choice wherein 
copy relocation is handled by linker at runtime and sanitizer does not interfere with it*/
