#include <stdio.h>

int main() {
    int value = 10;
    int *pointer = &value;

    printf("Value: %d\n", value);
    printf("Pointer: %p\n", pointer);
    printf("Dereferenced Pointer: %d\n", *pointer);

    return 0;
}
