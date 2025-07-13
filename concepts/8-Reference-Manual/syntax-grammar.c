#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void demonstrate_declarations(void);
void demonstrate_expressions(void);
void demonstrate_statements(void);
void demonstrate_preprocessing(void);

#define MAX_SIZE 100
#define SQUARE(x) ((x) * (x))
#define DEBUG 1

#ifdef DEBUG
    #define LOG(msg) printf("DEBUG: %s\n", msg)
#else
    #define LOG(msg)
#endif

struct Example {
    int id;
    char name[50];
    float value;
};

enum Color { RED, GREEN, BLUE };

union Data {
    int i;
    float f;
    char c;
};

typedef struct {
    int x, y;
} Point;

int main() {
    printf("C Language Reference Manual - Syntax and Grammar:\n\n");
    
    demonstrate_declarations();
    demonstrate_expressions();
    demonstrate_statements();
    demonstrate_preprocessing();
    
    return 0;
}

void demonstrate_declarations(void) {
    printf("=== DECLARATIONS ===\n");
    
    int integer = 42;
    float floating = 3.14f;
    double precision = 3.141592653589793;
    char character = 'A';
    char string[] = "Hello, World!";
    
    int array[5] = {1, 2, 3, 4, 5};
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    
    int *ptr = &integer;
    int **double_ptr = &ptr;
    
    int (*func_ptr)(int, int);
    
    const int constant = 100;
    const char *const_string = "Constant string";
    
    static int static_var = 10;
    extern int extern_var; 
    
    volatile int volatile_var = 20;
    
    register int reg_var = 30;
    
    printf("Variable declarations completed\n");
    
    struct Example example = {1, "Test", 99.9f};
    
    union Data data;
    data.i = 42;
    
    enum Color color = RED;
    
    Point point = {10, 20};
    
    printf("Complex type declarations completed\n\n");
}

void demonstrate_expressions(void) {
    printf("=== EXPRESSIONS ===\n");
    
    int a = 10, b = 20, c = 30;
    
    int sum = a + b;
    int difference = b - a;
    int product = a * b;
    int quotient = b / a;
    int remainder = b % a;
    
    printf("Arithmetic: %d + %d = %d\n", a, b, sum);
    
    int greater = (a > b);
    int less = (a < b);
    int equal = (a == b);
    int not_equal = (a != b);
    
    printf("Relational: %d > %d = %d\n", a, b, greater);
    
    int logical_and = (a > 0) && (b > 0);
    int logical_or = (a > 0) || (b < 0);
    int logical_not = !(a > b);
    
    printf("Logical: (%d > 0) && (%d > 0) = %d\n", a, b, logical_and);
    
    int bitwise_and = a & b;
    int bitwise_or = a | b;
    int bitwise_xor = a ^ b;
    int bitwise_not = ~a;
    int left_shift = a << 2;
    int right_shift = a >> 1;
    
    printf("Bitwise: %d & %d = %d\n", a, b, bitwise_and);
    
    int x = 5;
    x += 10; 
    x -= 3;   
    x *= 2;   
    x /= 4;  
    x %= 3; 
    
    printf("Assignment result: %d\n", x);
    
    int pre_inc = ++a;
    int post_inc = b++;
    int pre_dec = --c;
    
    printf("Pre-increment: %d, Post-increment: %d\n", pre_inc, post_inc);
    
    int max = (a > b) ? a : b;
    printf("Max of %d and %d is %d\n", a, b, max);
    
    int result = (a = 1, b = 2, a + b);
    printf("Comma expression result: %d\n", result);
    
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of array: %zu bytes\n", sizeof(array));
    
    float float_result = (float)a / b;
    printf("Cast result: %.2f\n", float_result);
    
    printf("\n");
}

void demonstrate_statements(void) {
    printf("=== STATEMENTS ===\n");
    
    int x = 10;
    x++; 
    
    {
        int local_var = 20;
        printf("Inside block: %d\n", local_var);
    }
    
    if (x > 5) {
        printf("x is greater than 5\n");
    } else if (x == 5) {
        printf("x equals 5\n");
    } else {
        printf("x is less than 5\n");
    }
    
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
        default:
            printf("Other day\n");
            break;
    }
    
    printf("While loop: ");
    int i = 0;
    while (i < 3) {
        printf("%d ", i);
        i++;
    }
    printf("\n");
    
    printf("For loop: ");
    for (int j = 0; j < 3; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    printf("Do-while loop: ");
    int k = 0;
    do {
        printf("%d ", k);
        k++;
    } while (k < 3);
    printf("\n");
    
    printf("Break and continue: ");
    for (int m = 0; m < 10; m++) {
        if (m == 2) continue; 
        if (m == 5) break;     
        printf("%d ", m);
    }
    printf("\n");
    
    int n = 0;
    loop_start:
        if (n < 3) {
            printf("Goto loop: %d\n", n);
            n++;
            goto loop_start;
        }
    
    printf("\n");
}

void demonstrate_preprocessing(void) {
    printf("=== PREPROCESSING ===\n");
    
    printf("MAX_SIZE = %d\n", MAX_SIZE);
    printf("SQUARE(5) = %d\n", SQUARE(5));
    
    LOG("This is a debug message");
    
    printf("File: %s\n", __FILE__);
    printf("Line: %d\n", __LINE__);
    printf("Date: %s\n", __DATE__);
    printf("Time: %s\n", __TIME__);
    
    #define CONCAT(a, b) a ## b
    int CONCAT(var, 123) = 456;
    printf("Concatenated variable: %d\n", var123);
    
    #define STRING(x) #x
    printf("Stringified: %s\n", STRING(Hello World));
    
    printf("Standard library limits:\n");
    printf("INT_MAX = %d\n", INT_MAX);
    printf("INT_MIN = %d\n", INT_MIN);
    
    printf("\n");
}
