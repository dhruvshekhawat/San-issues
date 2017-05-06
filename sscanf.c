/*Usage:
clang -fsanitize=memory -fsanitize-memory-track-origins -g sscanf.c && ./a.out
*/
#include <stdio.h>

int main(void)
{
        char *var;
        sscanf("False positive with MSAN", "%ms", &var);
        return var[0]; //this line throws error
}


