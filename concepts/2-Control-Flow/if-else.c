#include <stdio.h>

int main() {
    int number = 42;
    
    if (number > 0) {
        printf("%d is positive\n", number);
    }
    
    if (number % 2 == 0) {
        printf("%d is even\n", number);
    } else {
        printf("%d is odd\n", number);
    }
    
    if (number > 0) {
        if (number > 100) {
            printf("%d is a large positive number\n", number);
        } else {
            printf("%d is a small positive number\n", number);
        }
    } else if (number < 0) {
        printf("%d is negative\n", number);
    } else {
        printf("%d is zero\n", number);
    }
    
    char *result = (number > 50) ? "greater than 50" : "less than or equal to 50";
    printf("%d is %s\n", number, result);
    
    int score = 85;
    char grade;
    
    if (score >= 90) {
        grade = 'A';
    } else if (score >= 80) {
        grade = 'B';
    } else if (score >= 70) {
        grade = 'C';
    } else if (score >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }
    
    printf("Score %d gets grade %c\n", score, grade);
    
    return 0;
}
