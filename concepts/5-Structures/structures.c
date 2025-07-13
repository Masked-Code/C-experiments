#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};

struct Person {
    char name[50];
    int age;
    float height;
};

struct Rectangle {
    struct Point top_left;
    struct Point bottom_right;
};

void printPoint(struct Point p);
void printPerson(struct Person p);
float calculateArea(struct Rectangle rect);
struct Point addPoints(struct Point p1, struct Point p2);

int main() {
    printf("Structures in C:\n\n");
    
    struct Point p1 = {10, 20};
    struct Point p2;
    p2.x = 30;
    p2.y = 40;
    
    printf("Point 1: ");
    printPoint(p1);
    printf("Point 2: ");
    printPoint(p2);
    
    struct Person person1 = {"Alice", 25, 5.6};
    struct Person person2;
    strcpy(person2.name, "Bob");
    person2.age = 30;
    person2.height = 6.0;
    
    printf("\nPerson 1: ");
    printPerson(person1);
    printf("Person 2: ");
    printPerson(person2);
    
    struct Rectangle rect = {{0, 0}, {10, 5}};
    printf("\nRectangle area: %.2f\n", calculateArea(rect));
    
    struct Point sum = addPoints(p1, p2);
    printf("Sum of points: ");
    printPoint(sum);
    
    printf("\nArray of structures:\n");
    struct Person people[3] = {
        {"Charlie", 22, 5.8},
        {"Diana", 28, 5.4},
        {"Eve", 35, 5.9}
    };
    
    for (int i = 0; i < 3; i++) {
        printf("Person %d: ", i + 1);
        printPerson(people[i]);
    }
    
    printf("\nPointer to structure:\n");
    struct Person *ptr = &person1;
    printf("Name: %s, Age: %d, Height: %.1f\n", 
           ptr->name, ptr->age, ptr->height);
    
    printf("\nDynamic structure allocation:\n");
    struct Person *dynamic_person = (struct Person *)malloc(sizeof(struct Person));
    strcpy(dynamic_person->name, "Frank");
    dynamic_person->age = 45;
    dynamic_person->height = 5.7;
    
    printf("Dynamic person: ");
    printPerson(*dynamic_person);
    free(dynamic_person);
    
    printf("\nStructure assignment:\n");
    struct Point original = {100, 200};
    struct Point copy = original;  
    
    printf("Original: ");
    printPoint(original);
    printf("Copy: ");
    printPoint(copy);
    
    return 0;
}

void printPoint(struct Point p) {
    printf("(%d, %d)\n", p.x, p.y);
}

void printPerson(struct Person p) {
    printf("Name: %s, Age: %d, Height: %.1f\n", p.name, p.age, p.height);
}

float calculateArea(struct Rectangle rect) {
    int width = rect.bottom_right.x - rect.top_left.x;
    int height = rect.bottom_right.y - rect.top_left.y;
    return (float)(width * height);
}

struct Point addPoints(struct Point p1, struct Point p2) {
    struct Point result;
    result.x = p1.x + p2.x;
    result.y = p1.y + p2.y;
    return result;
}
