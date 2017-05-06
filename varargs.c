/*
vararg_check tries to access a non-existing variadic in line 9 but error is not thrown by any sanitizer.
*SAN find it difficult to map memory addresses of variadic arguments on the stack and hence do not monitor them.
*/
#include <stdarg.h>
#include <stdio.h>

void func(int first, ...) {
    va_list ap;
    va_start(ap, first);
    va_arg(ap, int);
    va_end(ap);
}

int main() {
    func(10);
    printf("Non-existing variadic called. But no error was thrown.\n");    
}
