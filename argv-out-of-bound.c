/*Usage:
clang -fsanitize=address argv-out-of-bound.c && ./a.out
*/
#include <stdio.h>

int main(int argc, char** argv) {
    printf("%d %s\n", argc, argv[5]); /*pass less than 5 args*/
}

/*Error is not thrown because the buffer for argv is created by libc, which is not instrumented*/
