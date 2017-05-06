/*-fno-common has to be given which is not mentioned explicitly anywhere other than FAQs*/
#include <stdio.h>

int test;

int main() {
    int *var = &test;
    printf("test %d\n", var[1]);
}
