#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    printf("C Language Reference - Keywords and Operators:\n\n");
    
    printf("=== STORAGE CLASS KEYWORDS ===\n");
    
    auto int auto_var = 10;    
    static int static_var = 20;   
    extern int extern_var;    
    register int reg_var = 30;  
    
    printf("auto_var: %d\n", auto_var);
    printf("static_var: %d\n", static_var);
    printf("reg_var: %d\n", reg_var);
    
    printf("\n=== TYPE QUALIFIERS ===\n");
    
    const int const_var = 100;   
    volatile int volatile_var = 200;
    
    printf("const_var: %d\n", const_var);
    printf("volatile_var: %d\n", volatile_var);
    
    printf("\n=== DATA TYPE KEYWORDS ===\n");
    
    char char_var = 'A';
    short short_var = 1000;
    int int_var = 50000;
    long long_var = 1000000L;
    float float_var = 3.14f;
    double double_var = 3.141592653589793;
    signed int signed_var = -100;
    unsigned int unsigned_var = 100U;
    void *void_ptr = NULL;
    
    printf("char: %c\n", char_var);
    printf("short: %d\n", short_var);
    printf("int: %d\n", int_var);
    printf("long: %ld\n", long_var);
    printf("float: %.2f\n", float_var);
    printf("double: %.6f\n", double_var);
    printf("signed: %d\n", signed_var);
    printf("unsigned: %u\n", unsigned_var);
    
    bool bool_var = true;
    printf("bool: %d\n", bool_var);
    
    printf("\n=== CONTROL FLOW KEYWORDS ===\n");
    
    if (int_var > 0) {
        printf("if-else: int_var is positive\n");
    } else {
        printf("if-else: int_var is not positive\n");
    }
    
    switch (char_var) {
        case 'A':
            printf("switch: Found A\n");
            break;
        case 'B':
            printf("switch: Found B\n");
            break;
        default:
            printf("switch: Other character\n");
            break;
    }
    
    printf("while: ");
    int i = 0;
    while (i < 3) {
        printf("%d ", i);
        i++;
    }
    printf("\n");
    
    printf("for: ");
    for (int j = 0; j < 3; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    printf("do-while: ");
    int k = 0;
    do {
        printf("%d ", k);
        k++;
    } while (k < 3);
    printf("\n");
    
    printf("break/continue: ");
    for (int m = 0; m < 10; m++) {
        if (m == 2) continue;
        if (m == 5) break;
        printf("%d ", m);
    }
    printf("\n");
    
    int n = 0;
    start:
        if (n < 2) {
            printf("goto: %d ", n);
            n++;
            goto start;
        }
    printf("\n");
    
    printf("return: Function will return 0\n");
    
    printf("\n=== OPERATORS ===\n");
    
    int a = 10, b = 3;
    
    printf("Arithmetic operators:\n");
    printf("a + b = %d\n", a + b);   
    printf("a - b = %d\n", a - b);  
    printf("a * b = %d\n", a * b);  
    printf("a / b = %d\n", a / b); 
    printf("a %% b = %d\n", a % b);   
    printf("++a = %d\n", ++a);    
    printf("b-- = %d\n", b--);      
    
    printf("\nRelational operators:\n");
    printf("a > b = %d\n", a > b);  
    printf("a < b = %d\n", a < b);
    printf("a >= b = %d\n", a >= b); 
    printf("a <= b = %d\n", a <= b); 
    printf("a == b = %d\n", a == b);  
    printf("a != b = %d\n", a != b); 
    
    printf("\nLogical operators:\n");
    printf("(a > 0) && (b > 0) = %d\n", (a > 0) && (b > 0));  
    printf("(a > 0) || (b < 0) = %d\n", (a > 0) || (b < 0));  
    printf("!(a > b) = %d\n", !(a > b));                  
    
    printf("\nBitwise operators:\n");
    printf("a & b = %d\n", a & b); 
    printf("a | b = %d\n", a | b);  
    printf("a ^ b = %d\n", a ^ b);   
    printf("~a = %d\n", ~a);        
    printf("a << 1 = %d\n", a << 1); 
    printf("a >> 1 = %d\n", a >> 1);  
    
    printf("\nAssignment operators:\n");
    int x = 5;
    printf("x = %d\n", x);
    x += 3; printf("x += 3: %d\n", x);
    x -= 2; printf("x -= 2: %d\n", x);
    x *= 2; printf("x *= 2: %d\n", x);
    x /= 3; printf("x /= 3: %d\n", x);
    x %= 3; printf("x %%= 3: %d\n", x);
    
    printf("\nOther operators:\n");
    printf("sizeof(int) = %zu\n", sizeof(int)); 
    printf("&a = %p\n", (void*)&a);           
    int *ptr = &a;
    printf("*ptr = %d\n", *ptr);       
    printf("a > b ? a : b = %d\n", a > b ? a : b);  
    
    int result = (a = 1, b = 2, a + b);
    printf("Comma operator result: %d\n", result);
    
    struct Point { int x, y; };
    struct Point point = {10, 20};
    struct Point *point_ptr = &point;
    
    printf("\nStructure operators:\n");
    printf("point.x = %d\n", point.x);  
    printf("point_ptr->y = %d\n", point_ptr->y); 
    
    int array[5] = {1, 2, 3, 4, 5};
    printf("array[2] = %d\n", array[2]);
    
    printf("printf is a function call operator example\n");
    
    return 0;
}
