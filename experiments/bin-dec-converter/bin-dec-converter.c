#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int binaryToDecimal(const char *binaryStr) {
    int decimal = 0;
    int len = strlen(binaryStr);

    for (int i = 0; i < len; i++) {
        if (binaryStr[i] != '0' && binaryStr[i] != '1') {
            printf("Invalid binary number.\n");
            return -1;
        }
        decimal = decimal * 2 + (binaryStr[i] - '0');
    }

    return decimal;
}

void decimalToBinary(int decimal) {
    if (decimal == 0) {
        printf("Binary: 0\n");
        return;
    }

    char binary[32];
    int index = 0;

    while (decimal > 0) {
        binary[index++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        putchar(binary[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    char binaryStr[65];
    int decimal;

    printf("Binary / Decimal Converter\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a binary number: ");
            scanf("%s", binaryStr);
            decimal = binaryToDecimal(binaryStr);
            if (decimal != -1) {
                printf("Decimal: %d\n", decimal);
            }
            break;
        case 2:
            printf("Enter a decimal number: ");
            scanf("%d", &decimal);
            decimalToBinary(decimal);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
