#include <stdio.h>

int factorial(int n);
int fibonacci(int n);
int power(int base, int exponent);
void printNumbers(int n);
int gcd(int a, int b);

int main() {
    printf("Recursion Examples:\n\n");
    
    printf("Factorial Examples:\n");
    for (int i = 0; i <= 5; i++) {
        printf("%d! = %d\n", i, factorial(i));
    }
    
    printf("\nFibonacci Sequence:\n");
    for (int i = 0; i < 10; i++) {
        printf("F(%d) = %d\n", i, fibonacci(i));
    }
    
    printf("\nPower Examples:\n");
    printf("2^3 = %d\n", power(2, 3));
    printf("5^4 = %d\n", power(5, 4));
    printf("3^0 = %d\n", power(3, 0));
    
    printf("\nCountdown from 5:\n");
    printNumbers(5);
    
    printf("\nGCD Examples:\n");
    printf("GCD(48, 18) = %d\n", gcd(48, 18));
    printf("GCD(100, 25) = %d\n", gcd(100, 25));
    
    return 0;
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    return base * power(base, exponent - 1);
}

void printNumbers(int n) {
    if (n <= 0) {
        return;
    }
    printf("%d ", n);
    printNumbers(n - 1);
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
