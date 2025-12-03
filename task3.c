#include <stddef.h>
#include <stdio.h>

static int arrays_equal(const int *lhs, const int *rhs, size_t len) {
    if (!lhs || !rhs) {
        return 0;
    }
    for (size_t i = 0; i < len; ++i) {
        if (lhs[i] != rhs[i]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int lhs[] = {4, 8, 15, 16};
    int rhs_good[] = {4, 8, 15, 16};
    int rhs_bad[] = {4, 8, 99, 16};
    printf("Task 3: arrays_equal(lhs, rhs_good) -> %d\n",
           arrays_equal(lhs, rhs_good, sizeof(lhs) / sizeof(lhs[0])));
    printf("Task 3: arrays_equal(lhs, rhs_bad)  -> %d\n",
           arrays_equal(lhs, rhs_bad, sizeof(lhs) / sizeof(lhs[0])));
    return 0;
}

