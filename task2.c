#include <stdio.h>

int main(void) {
    int values[3] = {10, 30, 2000};
    int *values_ptr = values;
    puts("Task 2: array traversal via pointer");
    for (size_t i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
        printf("  values[%zu] = %d (address=%p)\n", i, *(values_ptr + i),
               (void *)(values_ptr + i));
    }
    return 0;
}

