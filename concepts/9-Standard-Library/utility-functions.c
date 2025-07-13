#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdarg.h>
#include <errno.h>
#include <limits.h>

void print_integers(int count, ...) {
    va_list args;
    va_start(args, count);
    
    printf("Variable arguments: ");
    for (int i = 0; i < count; i++) {
        int value = va_arg(args, int);
        printf("%d ", value);
    }
    printf("\n");
    
    va_end(args);
}

int compare_ints(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

int main() {
    printf("C Standard Library - Utility Functions:\n\n");
    
    printf("=== MEMORY ALLOCATION ===\n");
    
    int *numbers = (int*)malloc(5 * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    for (int i = 0; i < 5; i++) {
        numbers[i] = i * 10;
    }
    
    printf("Initial array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    numbers = (int*)realloc(numbers, 10 * sizeof(int));
    if (numbers == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }
    
    for (int i = 5; i < 10; i++) {
        numbers[i] = i * 10;
    }
    
    printf("Reallocated array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    int *zeros = (int*)calloc(5, sizeof(int));
    if (zeros != NULL) {
        printf("Calloc array: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", zeros[i]);
        }
        printf("\n");
        free(zeros);
    }
    
    printf("\n=== STRING CONVERSION ===\n");
    
    char *str_num = "12345";
    char *str_float = "3.14159";
    char *str_hex = "0xFF";
    char *str_invalid = "123abc";
    
    int num = atoi(str_num);
    printf("atoi(\"%s\") = %d\n", str_num, num);
    
    double fnum = atof(str_float);
    printf("atof(\"%s\") = %.5f\n", str_float, fnum);
    
    char *endptr;
    long lnum = strtol(str_invalid, &endptr, 10);
    printf("strtol(\"%s\", base 10) = %ld, stopped at: '%s'\n", 
           str_invalid, lnum, endptr);
    
    unsigned long hex_num = strtoul(str_hex, &endptr, 16);
    printf("strtoul(\"%s\", base 16) = %lu\n", str_hex, hex_num);
    
    char buffer[50];
    sprintf(buffer, "Number: %d, Float: %.2f", 42, 3.14);
    printf("sprintf result: %s\n", buffer);
    
    printf("\n=== RANDOM NUMBERS ===\n");
    
    srand((unsigned int)time(NULL));
    
    printf("Random numbers: ");
    for (int i = 0; i < 5; i++) {
        int random = rand() % 100; 
        printf("%d ", random);
    }
    printf("\n");
    
    printf("Random floats: ");
    for (int i = 0; i < 5; i++) {
        float random_float = (float)rand() / RAND_MAX;
        printf("%.3f ", random_float);
    }
    printf("\n");
    
    printf("\n=== SEARCHING AND SORTING ===\n");
    
    int search_array[] = {64, 34, 25, 12, 22, 11, 90};
    int array_size = sizeof(search_array) / sizeof(search_array[0]);
    
    printf("Original array: ");
    for (int i = 0; i < array_size; i++) {
        printf("%d ", search_array[i]);
    }
    printf("\n");
    
    qsort(search_array, array_size, sizeof(int), compare_ints);
    
    printf("Sorted array: ");
    for (int i = 0; i < array_size; i++) {
        printf("%d ", search_array[i]);
    }
    printf("\n");
    
    int key = 25;
    int *found = (int*)bsearch(&key, search_array, array_size, 
                              sizeof(int), compare_ints);
    if (found) {
        printf("Found %d in sorted array\n", key);
    } else {
        printf("Key %d not found\n", key);
    }
    
    printf("\n=== TIME FUNCTIONS ===\n");
    
    time_t current_time = time(NULL);
    printf("Current time (seconds since epoch): %ld\n", current_time);
    
    char *time_str = ctime(&current_time);
    printf("Current time string: %s", time_str);
    
    struct tm *local_time = localtime(&current_time);
    printf("Year: %d, Month: %d, Day: %d\n", 
           local_time->tm_year + 1900, 
           local_time->tm_mon + 1, 
           local_time->tm_mday);
    
    char time_buffer[100];
    strftime(time_buffer, sizeof(time_buffer), 
             "%Y-%m-%d %H:%M:%S", local_time);
    printf("Formatted time: %s\n", time_buffer);
    
    clock_t start = clock();
    
    volatile int sum = 0;
    for (int i = 0; i < 1000000; i++) {
        sum += i;
    }
    
    clock_t end = clock();
    double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Computation took %.6f seconds\n", cpu_time);
    
    printf("\n=== VARIABLE ARGUMENTS ===\n");
    print_integers(3, 10, 20, 30);
    print_integers(5, 1, 2, 3, 4, 5);
    
    printf("\n=== ASSERTIONS ===\n");
    int x = 10;
    assert(x > 0); 
    printf("Assertion passed: x > 0\n");
    
    printf("\n=== ERROR HANDLING ===\n");
    
    FILE *file = fopen("nonexistent.txt", "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        printf("Error code: %d\n", errno);
    }
    
    printf("\n=== ENVIRONMENT ===\n");
    
    char *home = getenv("HOME");
    if (home) {
        printf("HOME environment variable: %s\n", home);
    } else {
        printf("HOME environment variable not set\n");
    }
    
    printf("\n=== SYSTEM COMMAND ===\n");
    printf("Executing system command...\n");
    int result = system("echo Hello from system command");
    printf("System command returned: %d\n", result);
    
    printf("\n=== ABSOLUTE VALUES ===\n");
    printf("abs(-42) = %d\n", abs(-42));
    printf("labs(-1234567L) = %ld\n", labs(-1234567L));
    printf("fabs(-3.14) = %.2f\n", fabs(-3.14));
    
    div_t div_result = div(17, 5);
    printf("div(17, 5): quotient = %d, remainder = %d\n", 
           div_result.quot, div_result.rem);
    
    free(numbers);
    
    printf("\nProgram completed successfully\n");
    return 0;
}
