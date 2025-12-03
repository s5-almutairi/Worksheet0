#include <stdio.h>

static void swap(void *x, void *y) {
    if (!x || !y) {
        return;
    }
    int tmp = *(int *)x;
    *(int *)x = *(int *)y;
    *(int *)y = tmp;
}

int main(void) {
    int a = 5;
    int b = 42;
    printf("Task 5: before swap a=%d b=%d\n", a, b);
    swap(&a, &b);
    printf("Task 5: after  swap a=%d b=%d\n", a, b);
    return 0;
}

