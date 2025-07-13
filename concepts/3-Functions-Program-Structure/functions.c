#include <stdio.h>

int add(int a, int b);
int factorial(int n);
void greet(char name[]);
int max(int a, int b);
void swap(int *a, int *b);

int main() {
    printf("Function calls demonstration:\n");
    
    int result = add(5, 3);
    printf("5 + 3 = %d\n", result);
    
    int fact = factorial(5);
    printf("5! = %d\n", fact);
    
    greet("Alice");
    
    int maximum = max(10, 20);
    printf("max(10, 20) = %d\n", maximum);
    
    int x = 10, y = 20;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);
    
    return 0;
}

int add(int a, int b) {
    return a + b;
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1); 
}

void greet(char name[]) {
    printf("Hello, %s!\n", name);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
