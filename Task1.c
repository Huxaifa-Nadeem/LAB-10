#include <stdio.h>

void printArrayRecursive(int arr[], int size) {
    if (size == 0)
        return;
    printf("%d\n", arr[0]);
    printArrayRecursive(arr + 1, size - 1);
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    printArrayRecursive(array, size);
    return 0;
}
