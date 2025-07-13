#include <stdio.h>

int main() {
    printf("Counting up with while loop:\n");
    int i = 1;
    while (i <= 5) {
        printf("%d ", i);
        i++;
    }
    printf("\n\n");
    
    printf("Counting down with while loop:\n");
    int j = 5;
    while (j >= 1) {
        printf("%d ", j);
        j--;
    }
    printf("\n\n");
    
    printf("Do-while loop example:\n");
    int k = 10;
    do {
        printf("k = %d\n", k);
        k++;
    } while (k < 10); 
    
    printf("\nInput validation example:\n");
    int choice;
    do {
        printf("Enter a number between 1 and 3: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 3) {
            printf("Invalid choice! Try again.\n");
        }
    } while (choice < 1 || choice > 3);
    
    printf("You chose: %d\n", choice);
    
    printf("\nSum of numbers 1 to 10:\n");
    int sum = 0;
    int num = 1;
    while (num <= 10) {
        sum += num;
        num++;
    }
    printf("Sum = %d\n", sum);
    
    return 0;
}
