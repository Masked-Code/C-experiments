#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size);
void modifyArray(int arr[], int size);

int main() {
    printf("Array Basics and Operations:\n\n");
    
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Original array:\n");
    printArray(numbers, size);
    
    modifyArray(numbers, size);
    printf("\nModified array:\n");
    printArray(numbers, size);
    
    printf("\nMulti-dimensional Array:\n");
    int matrix[2][2] = {{1, 2}, {3, 4}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("matrix[%d][%d] = %d\n", i, j, matrix[i][j]);
        }
    }
    
    printf("\nArray and Pointer Relationship:\n");
    int *ptr = numbers; 
    printf("First element using pointer: %d\n", *ptr);
    
    printf("Array elements using pointer arithmetic:\n");
    for (int i = 0; i < size; i++) {
        printf("*(ptr + %d) = %d\n", i, *(ptr + i));
    }
    
    printf("\nDynamic Array Example:\n");
    int *dynamicArray = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = i + 10;
    }
    
    printf("Dynamic array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("dynamicArray[%d] = %d\n", i, dynamicArray[i]);
    }
    
    free(dynamicArray);
    
    return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void modifyArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}
