#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Standard Input/Output in C:\n\n");
    
    printf("Basic I/O Examples:\n");
    char name[50];
    int age;
    float height;
    
    printf("Enter your name: ");
    scanf("%s", name);
    
    printf("Enter your age: ");
    scanf("%d", &age);
    
    printf("Enter your height: ");
    scanf("%f", &height);
    
    printf("\nYour information:\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Height: %.2f\n", height);
    
    printf("\nCharacter I/O:\n");
    printf("Enter a character: ");
    char ch;
    scanf(" %c", &ch);
    printf("You entered: %c\n", ch);
    
    printf("\nString I/O:\n");
    char buffer[100];
    printf("Enter a line of text: ");
    scanf(" %[^\n]", buffer); 
    printf("You entered: %s\n", buffer);
    
    printf("\nFormatted Output:\n");
    int num = 42;
    float pi = 3.14159;
    
    printf("Integer: %d\n", num);
    printf("Integer (5 digits): %5d\n", num);
    printf("Integer (zero-padded): %05d\n", num);
    printf("Float: %f\n", pi);
    printf("Float (2 decimals): %.2f\n", pi);
    printf("Float (scientific): %e\n", pi);
    printf("Hexadecimal: %x\n", num);
    printf("Octal: %o\n", num);
    
    printf("\nMultiple values:\n");
    int x = 10, y = 20;
    printf("x = %d, y = %d, sum = %d\n", x, y, x + y);
    
    printf("\nCharacter manipulation:\n");
    char c1 = 'A', c2 = 'a';
    printf("Uppercase: %c, Lowercase: %c\n", c1, c2);
    printf("ASCII values: %d, %d\n", c1, c2);
    
    printf("\nCounting characters in input:\n");
    printf("Enter some text (press Enter): ");
    int count = 0;
    char input;
    scanf(" %c", &input); 
    
    while ((input = getchar()) != '\n') {
        count++;
    }
    
    printf("You entered %d characters\n", count);
    
    printf("\nPrintf return value:\n");
    int chars_printed = printf("This string has some characters");
    printf("\nCharacters printed: %d\n", chars_printed);
    
    return 0;
}
