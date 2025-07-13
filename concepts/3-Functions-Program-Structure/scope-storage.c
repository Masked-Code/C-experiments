#include <stdio.h>

int global_var = 100;
static int static_global = 200;

void demonstrate_local_scope();
void demonstrate_static_local();
void demonstrate_global_scope();

int main() {
    printf("Variable Scope and Storage Classes Demo:\n\n");
    
    int local_main = 10;
    printf("Local variable in main: %d\n", local_main);
    printf("Global variable: %d\n", global_var);
    
    demonstrate_local_scope();
    demonstrate_static_local();
    demonstrate_global_scope();
    
    {
        int block_var = 50;
        printf("Block variable: %d\n", block_var);
        
        int global_var = 300;
        printf("Shadowed global_var in block: %d\n", global_var);
    }
    
    printf("Global variable after block: %d\n", global_var);
    
    return 0;
}

void demonstrate_local_scope() {
    printf("\n--- Local Scope Demo ---\n");
    int local_var = 20;
    printf("Local variable in function: %d\n", local_var);
    
    printf("Global variable from function: %d\n", global_var);
    
    global_var = 150;
    printf("Modified global variable: %d\n", global_var);
}

void demonstrate_static_local() {
    printf("\n--- Static Local Variable Demo ---\n");
    static int static_local = 0; 
    int regular_local = 0;
    
    static_local++;
    regular_local++;
    
    printf("Static local: %d, Regular local: %d\n", static_local, regular_local);
    
    static void inner_function() {
        static int count = 0;
        count++;
        printf("Inner function called %d times\n", count);
    }
    
    inner_function();
    inner_function();
}

void demonstrate_global_scope() {
    printf("\n--- Global Scope Demo ---\n");
    printf("Global variable: %d\n", global_var);
    printf("Static global variable: %d\n", static_global);
    
    global_var = 999;
    printf("Modified global variable: %d\n", global_var);
    
    static_global = 777;
    printf("Modified static global variable: %d\n", static_global);
}
