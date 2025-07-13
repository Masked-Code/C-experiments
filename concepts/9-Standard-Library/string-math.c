#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main() {
    printf("C Standard Library - String and Math Functions:\n\n");
    
    printf("=== STRING FUNCTIONS ===\n");
    
    char str1[50] = "Hello";
    char str2[50] = "World";
    char str3[100];
    char str4[50] = "hello world";
    
    printf("strlen(\"%s\") = %zu\n", str1, strlen(str1));
    
    strcpy(str3, str1);
    printf("strcpy result: %s\n", str3);
    
    strcat(str3, " ");
    strcat(str3, str2);
    printf("strcat result: %s\n", str3);
    
    int cmp = strcmp(str1, str2);
    printf("strcmp(\"%s\", \"%s\") = %d\n", str1, str2, cmp);
    
    char safe_str[20];
    strncpy(safe_str, str4, 5);
    safe_str[5] = '\0';
    printf("strncpy result: %s\n", safe_str);
    
    char *pos = strstr(str4, "world");
    if (pos) {
        printf("strstr found 'world' at position: %ld\n", pos - str4);
    }
    
    char *chr_pos = strchr(str4, 'w');
    if (chr_pos) {
        printf("strchr found 'w' at position: %ld\n", chr_pos - str4);
    }
    
    char tokenize_str[] = "apple,banana,orange";
    printf("String tokenization: \"%s\"\n", tokenize_str);
    char *token = strtok(tokenize_str, ",");
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, ",");
    }
    
    printf("\nMemory functions:\n");
    char mem1[10] = "Hello";
    char mem2[10];
    
    memcpy(mem2, mem1, 6);
    printf("memcpy result: %s\n", mem2);
    
    memset(mem2, 'X', 3);
    mem2[3] = '\0';
    printf("memset result: %s\n", mem2);
    
    char mem3[] = "Hello";
    char mem4[] = "Hello";
    int mem_cmp = memcmp(mem3, mem4, 5);
    printf("memcmp result: %d\n", mem_cmp);
    
    printf("\n=== CHARACTER FUNCTIONS ===\n");
    
    char test_chars[] = "Hello World 123!";
    printf("Testing string: \"%s\"\n", test_chars);
    
    for (int i = 0; test_chars[i] != '\0'; i++) {
        char ch = test_chars[i];
        printf("'%c': ", ch);
        
        if (isalpha(ch)) printf("alpha ");
        if (isdigit(ch)) printf("digit ");
        if (isalnum(ch)) printf("alnum ");
        if (islower(ch)) printf("lower ");
        if (isupper(ch)) printf("upper ");
        if (isspace(ch)) printf("space ");
        if (ispunct(ch)) printf("punct ");
        
        printf("\n");
    }
    
    printf("\nCharacter conversion:\n");
    char lower_char = 'a';
    char upper_char = 'A';
    printf("toupper('%c') = '%c'\n", lower_char, toupper(lower_char));
    printf("tolower('%c') = '%c'\n", upper_char, tolower(upper_char));
    
    printf("\n=== MATH FUNCTIONS ===\n");
    
    double x = 16.0;
    double y = 3.0;
    double angle = 45.0;
    double radians = angle * M_PI / 180.0;
    
    printf("sqrt(%.1f) = %.2f\n", x, sqrt(x));
    printf("pow(%.1f, %.1f) = %.2f\n", x, y, pow(x, y));
    printf("fabs(-%.1f) = %.2f\n", x, fabs(-x));
    printf("floor(%.1f) = %.2f\n", x, floor(x));
    printf("ceil(%.1f) = %.2f\n", x, ceil(x));
    
    printf("\nTrigonometric functions (%.1f degrees):\n", angle);
    printf("sin(%.1f°) = %.3f\n", angle, sin(radians));
    printf("cos(%.1f°) = %.3f\n", angle, cos(radians));
    printf("tan(%.1f°) = %.3f\n", angle, tan(radians));
    
    printf("asin(0.5) = %.3f rad (%.1f°)\n", 
           asin(0.5), asin(0.5) * 180.0 / M_PI);
    printf("acos(0.5) = %.3f rad (%.1f°)\n", 
           acos(0.5), acos(0.5) * 180.0 / M_PI);
    printf("atan(1.0) = %.3f rad (%.1f°)\n", 
           atan(1.0), atan(1.0) * 180.0 / M_PI);
    
    printf("\nLogarithmic functions:\n");
    printf("log(%.1f) = %.3f (natural log)\n", x, log(x));
    printf("log10(%.1f) = %.3f (base 10)\n", x, log10(x));
    printf("exp(%.1f) = %.3f (e^x)\n", y, exp(y));
    
    printf("\nHyperbolic functions:\n");
    printf("sinh(%.1f) = %.3f\n", y, sinh(y));
    printf("cosh(%.1f) = %.3f\n", y, cosh(y));
    printf("tanh(%.1f) = %.3f\n", y, tanh(y));
    
    printf("\nRounding functions:\n");
    double value = 3.7;
    printf("round(%.1f) = %.0f\n", value, round(value));
    printf("trunc(%.1f) = %.0f\n", value, trunc(value));
    
    printf("fmod(%.1f, %.1f) = %.2f\n", x, y, fmod(x, y));
    
    printf("\nSpecial math constants:\n");
    printf("M_PI = %.6f\n", M_PI);
    printf("M_E = %.6f\n", M_E);
    
    printf("\nMath error handling:\n");
    double result = sqrt(-1.0);
    if (isnan(result)) {
        printf("sqrt(-1) = NaN (Not a Number)\n");
    }
    
    result = 1.0 / 0.0;
    if (isinf(result)) {
        printf("1/0 = Infinity\n");
    }
    
    return 0;
}
