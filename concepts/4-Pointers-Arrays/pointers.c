#include <stdio.h>

int main() {
    printf("Pointer Basics Demo:\n\n");
    
    int var = 42;
    int *ptr = &var; 
    
    printf("Variable value: %d\n", var);
    printf("Variable address: %p\n", (void*)&var);
    printf("Pointer value (address it points to): %p\n", (void*)ptr);
    printf("Value at pointer (dereferencing): %d\n", *ptr);
    
    *ptr = 100;
    printf("\nAfter modifying through pointer:\n");
    printf("Variable value: %d\n", var);
    printf("Value at pointer: %d\n", *ptr);
    
    printf("\nPointer Arithmetic:\n");
    int arr[5] = {10, 20, 30, 40, 50};
    int *arr_ptr = arr; 
    
    printf("Array elements using pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d, *(arr_ptr + %d) = %d\n", 
               i, arr[i], i, *(arr_ptr + i));
    }
    
    printf("\nPointer to Pointer:\n");
    int value = 123;
    int *ptr1 = &value;
    int **ptr2 = &ptr1; 
    
    printf("Value: %d\n", value);
    printf("Through ptr1: %d\n", *ptr1);
    printf("Through ptr2: %d\n", **ptr2);
    
    printf("\nNull Pointer:\n");
    int *null_ptr = NULL;
    if (null_ptr == NULL) {
        printf("Pointer is NULL\n");
    }
    
    printf("\nPointer Comparison:\n");
    int a = 10, b = 20;
    int *pa = &a, *pb = &b;
    
    printf("pa == pb: %d\n", pa == pb);
    printf("pa < pb: %d\n", pa < pb);
    
    printf("\nFunction Pointer:\n");
    int (*func_ptr)(int, int) = NULL; 
    
    int add(int x, int y) {
        return x + y;
    }
    
    func_ptr = add;
    printf("Function result: %d\n", func_ptr(5, 3));
    
    return 0;
}
