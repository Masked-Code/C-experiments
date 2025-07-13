#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printString(char *str);
int stringLength(char *str);
void stringCopy(char *dest, char *src);
void stringConcatenate(char *dest, char *src);

int main() {
    printf("String Manipulation with Arrays and Pointers:\n\n");
    
    char str1[] = "Hello";
    char str2[] = {'W', 'o', 'r', 'l', 'd', '\0'};
    char *str3 = "Programming";
    
    printf("String literals and arrays:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);
    
    printf("\nString lengths:\n");
    printf("Length of str1: %d\n", stringLength(str1));
    printf("Length of str2: %d\n", stringLength(str2));
    printf("Using strlen: %zu\n", strlen(str3));
    
    printf("\nString copying:\n");
    char buffer[50];
    stringCopy(buffer, str1);
    printf("Copied string: %s\n", buffer);
    
    printf("\nString concatenation:\n");
    char result[100];
    strcpy(result, str1);
    strcat(result, " ");
    strcat(result, str2);
    printf("Concatenated: %s\n", result);
    
    printf("\nCharacter by character processing:\n");
    char *text = "Hello World";
    printf("Original: %s\n", text);
    printf("Characters: ");
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c ", text[i]);
    }
    printf("\n");
    
    printf("\nString comparison:\n");
    char *str_a = "Apple";
    char *str_b = "Banana";
    printf("strcmp(\"%s\", \"%s\") = %d\n", str_a, str_b, strcmp(str_a, str_b));
    
    printf("\nDynamic string allocation:\n");
    char *dynamic_str = (char *)malloc(20 * sizeof(char));
    strcpy(dynamic_str, "Dynamic String");
    printf("Dynamic string: %s\n", dynamic_str);
    free(dynamic_str);
    
    printf("\nArray of strings:\n");
    char *languages[] = {"C", "Python", "Java", "JavaScript"};
    int num_languages = sizeof(languages) / sizeof(languages[0]);
    
    for (int i = 0; i < num_languages; i++) {
        printf("Language %d: %s\n", i + 1, languages[i]);
    }
    
    return 0;
}

void printString(char *str) {
    printf("%s", str);
}

int stringLength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringCopy(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void stringConcatenate(char *dest, char *src) {
    int dest_len = stringLength(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
}
