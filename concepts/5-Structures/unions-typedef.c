#include <stdio.h>
#include <string.h>

typedef int Integer;
typedef char* String;

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

union Data {
    int i;
    float f;
    char str[20];
};

typedef union {
    int as_int;
    float as_float;
    char as_bytes[4];
} Number;

typedef enum {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} Day;

int main() {
    printf("Unions and Typedef in C:\n\n");
    
    printf("Typedef examples:\n");
    Integer num = 42;
    String message = "Hello, World!";
    
    printf("Integer: %d\n", num);
    printf("String: %s\n", message);
    
    Point p1 = {10, 20};
    Point p2;
    p2.x = 30;
    p2.y = 40;
    
    printf("\nPoint 1: (%d, %d)\n", p1.x, p1.y);
    printf("Point 2: (%d, %d)\n", p2.x, p2.y);
    
    Employee emp = {"John Doe", 30, 50000.0};
    printf("\nEmployee: %s, Age: %d, Salary: %.2f\n", 
           emp.name, emp.age, emp.salary);
    
    printf("\nUnion examples:\n");
    union Data data;
    
    data.i = 10;
    printf("data.i = %d\n", data.i);
    
    data.f = 3.14;
    printf("data.f = %.2f\n", data.f);
    printf("data.i = %d (corrupted)\n", data.i); 
    
    strcpy(data.str, "Hello");
    printf("data.str = %s\n", data.str);
    printf("data.i = %d (corrupted)\n", data.i);
    
    printf("\nNumber union with typedef:\n");
    Number num_union;
    
    num_union.as_int = 0x41200000; 
    printf("As int: %d\n", num_union.as_int);
    printf("As float: %.2f\n", num_union.as_float);
    
    printf("As bytes: ");
    for (int i = 0; i < 4; i++) {
        printf("%02X ", (unsigned char)num_union.as_bytes[i]);
    }
    printf("\n");
    
    printf("\nEnum with typedef:\n");
    Day today = FRIDAY;
    Day weekend = SATURDAY;
    
    printf("Today: %d\n", today);
    printf("Weekend: %d\n", weekend);
    
    printf("\nSize comparisons:\n");
    printf("Size of Point structure: %zu bytes\n", sizeof(Point));
    printf("Size of Employee structure: %zu bytes\n", sizeof(Employee));
    printf("Size of Data union: %zu bytes\n", sizeof(union Data));
    printf("Size of Number union: %zu bytes\n", sizeof(Number));
    printf("Size of Day enum: %zu bytes\n", sizeof(Day));
    
    printf("\nArray of typedef structures:\n");
    Point points[3] = {{0, 0}, {10, 10}, {20, 20}};
    
    for (int i = 0; i < 3; i++) {
        printf("Point %d: (%d, %d)\n", i, points[i].x, points[i].y);
    }
    
    return 0;
}
