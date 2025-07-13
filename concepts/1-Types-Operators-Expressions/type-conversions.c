#include <stdio.h>

int main() {
    int i = 42;
    float f = i;  
    double d = f;
    
    printf("Implicit conversions:\n");
    printf("int %d -> float %.2f -> double %.2f\n", i, f, d);
    
    double pi = 3.14159;
    int truncated = (int)pi;
    
    printf("\nExplicit casting:\n");
    printf("double %.5f -> int %d\n", pi, truncated);
    
    int a = 7, b = 3;
    printf("\nMixed arithmetic:\n");
    printf("int division: %d / %d = %d\n", a, b, a / b);
    printf("float division: %d / %d = %.2f\n", a, b, (float)a / b);
    
    char c1 = 'A';
    char c2 = 'Z';
    printf("\nCharacter arithmetic:\n");
    printf("'A' = %d\n", c1);
    printf("'Z' = %d\n", c2);
    printf("'Z' - 'A' = %d\n", c2 - c1);
    
    unsigned int ui = 4294967295U;
    int si = -1;
    printf("\nUnsigned vs signed:\n");
    printf("unsigned: %u\n", ui);
    printf("signed: %d\n", si);
    printf("comparison (ui > si): %d\n", ui > si);
    
    return 0;
}
