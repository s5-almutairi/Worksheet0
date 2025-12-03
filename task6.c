#include <stdio.h>

static void print_array(int *arr, int width, int height) {
    if (!arr || width <= 0 || height <= 0) {
        puts("print_array received invalid parameters.");
        return;
    }
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            int value = *(arr + row * width + col);
            printf("%4d", value);
        }
        putchar('\n');
    }
}

int main(void) {
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6},
    };
    puts("Task 6: print_array output");
    print_array(&matrix[0][0], 3, 2);
    return 0;
}

