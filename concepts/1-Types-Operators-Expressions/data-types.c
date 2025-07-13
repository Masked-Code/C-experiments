#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    char c = 'A';
    short s = 32767;
    int i = 2147483647;
    long l = 2147483647L;
    
    float f = 3.14159f;
    double d = 3.141592653589793;
    
    unsigned int ui = 4294967295U;
    unsigned char uc = 255;
    
    printf("Character: %c\n", c);
    printf("Short: %d\n", s);
    printf("Integer: %d\n", i);
    printf("Long: %ld\n", l);
    printf("Float: %.5f\n", f);
    printf("Double: %.15f\n", d);
    printf("Unsigned int: %u\n", ui);
    printf("Unsigned char: %u\n", uc);
    
    printf("\nType sizes:\n");
    printf("char: %zu bytes\n", sizeof(char));
    printf("short: %zu bytes\n", sizeof(short));
    printf("int: %zu bytes\n", sizeof(int));
    printf("long: %zu bytes\n", sizeof(long));
    printf("float: %zu bytes\n", sizeof(float));
    printf("double: %zu bytes\n", sizeof(double));
    
    return 0;
}
