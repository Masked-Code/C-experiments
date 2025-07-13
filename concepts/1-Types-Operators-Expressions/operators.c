#include <stdio.h>

int main() {
    int a = 15, b = 4;
    int x = 5, y = 3;
    
    printf("Arithmetic Operators:\n");
    printf("a = %d, b = %d\n", a, b);
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n", a % b);
    
    printf("\nRelational Operators:\n");
    printf("a > b: %d\n", a > b);
    printf("a < b: %d\n", a < b);
    printf("a >= b: %d\n", a >= b);
    printf("a <= b: %d\n", a <= b);
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n", a != b);
    
    printf("\nLogical Operators:\n");
    printf("x = %d, y = %d\n", x, y);
    printf("x && y: %d\n", x && y);
    printf("x || y: %d\n", x || y);
    printf("!x: %d\n", !x);
    
    printf("\nBitwise Operators:\n");
    printf("a & b: %d\n", a & b);
    printf("a | b: %d\n", a | b);
    printf("a ^ b: %d\n", a ^ b);
    printf("~a: %d\n", ~a);
    printf("a << 1: %d\n", a << 1);
    printf("a >> 1: %d\n", a >> 1);
    
    printf("\nIncrement/Decrement:\n");
    printf("++a: %d\n", ++a);
    printf("b--: %d\n", b--);
    printf("a after increment: %d\n", a);
    printf("b after decrement: %d\n", b);
    
    return 0;
}
