#include <stdio.h>

int main() {
    printf("Switch statement example:\n");
    int day = 3;
    
    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
        case 7:
            printf("Weekend\n");
            break;
        default:
            printf("Invalid day\n");
    }
    
    printf("\nCalculator example:\n");
    int a = 10, b = 5;
    char op = '+';
    
    switch (op) {
        case '+':
            printf("%d + %d = %d\n", a, b, a + b);
            break;
        case '-':
            printf("%d - %d = %d\n", a, b, a - b);
            break;
        case '*':
            printf("%d * %d = %d\n", a, b, a * b);
            break;
        case '/':
            if (b != 0) {
                printf("%d / %d = %.2f\n", a, b, (float)a / b);
            } else {
                printf("Error: Division by zero\n");
            }
            break;
        default:
            printf("Invalid operator\n");
    }
    
    printf("\nBreak example (stop at 5):\n");
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            printf("Breaking at %d\n", i);
            break;
        }
        printf("%d ", i);
    }
    printf("\n\n");
    
    printf("Continue example (skip even numbers):\n");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;
        }
        printf("%d ", i);
    }
    printf("\n\n");
    
    printf("Nested loops with break and continue:\n");
    for (int i = 1; i <= 3; i++) {
        printf("Outer loop: %d\n", i);
        for (int j = 1; j <= 5; j++) {
            if (j == 3) {
                continue; 
            }
            if (j == 5) {
                break; 
            }
            printf("  Inner loop: %d\n", j);
        }
    }
    
    return 0;
}
