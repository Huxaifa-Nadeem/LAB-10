#include <stdio.h>

int linearSearch(int arr[], int arrSize, int target, int currentIndex) {
    if (currentIndex >= arrSize) return -1;
    if (arr[currentIndex] == target) return currentIndex;
    return linearSearch(arr, arrSize, target, currentIndex + 1);
}

int main() {
    int numbers[] = {2, 4, 6, 8, 10, 12};
    int arrSize = sizeof(numbers) / sizeof(numbers[0]);
    int targetValue = 8;
    
    int resultIndex = linearSearch(numbers, arrSize, targetValue, 0);
    
    if (resultIndex != -1) {
        printf("Element found at index %d\n", resultIndex);
    } else {
        printf("Element not found\n");
    }
    
    return 0;
}
