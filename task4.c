#include <errno.h>
#include <stdio.h>
#include <string.h>

static int sum_file(const char *path) {
    FILE *fp = fopen("foo.txt", "r");
    if (!fp) {
        fprintf(stderr, "Failed to open %s: %s\n", path, strerror(errno));
        return 0;
    }
    int total = 0;
    int value;
    while (fscanf(fp, "%d", &value) == 1) {
        total += value;
    }
    fclose(fp);
    return total;
}

int main(void) {
    int result = sum_file("pointer_tasks/foo.txt");
    printf("Task 4: sum of numbers in foo.txt = %d\n", result);
    return 0;
}

