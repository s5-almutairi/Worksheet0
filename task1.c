
#include <stdio.h>

int main(void) {
    int n = 41;
    int *ptr_to_n = &n;
    (*ptr_to_n)++;
    printf("Task 1: n incremented via ptr_to_n = %d\n", n);
    return 0;
}

