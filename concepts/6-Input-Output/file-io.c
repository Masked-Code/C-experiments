#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("File Input/Output in C:\n\n");
    
    printf("Writing to a file:\n");
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }
    
    fprintf(output_file, "Hello, File I/O!\n");
    fprintf(output_file, "This is line 2.\n");
    fprintf(output_file, "Number: %d\n", 42);
    fprintf(output_file, "Float: %.2f\n", 3.14159);
    
    fclose(output_file);
    printf("Data written to output.txt\n");
    
    printf("\nReading from a file:\n");
    FILE *input_file = fopen("output.txt", "r");
    if (input_file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    
    char line[100];
    while (fgets(line, sizeof(line), input_file) != NULL) {
        printf("Read: %s", line);
    }
    
    fclose(input_file);
    
    printf("\nCharacter-by-character reading:\n");
    input_file = fopen("output.txt", "r");
    if (input_file != NULL) {
        int ch;
        int char_count = 0;
        
        while ((ch = fgetc(input_file)) != EOF) {
            putchar(ch);
            char_count++;
        }
        
        printf("\nTotal characters: %d\n", char_count);
        fclose(input_file);
    }
    
    printf("\nBinary file operations:\n");
    
    FILE *binary_file = fopen("data.bin", "wb");
    if (binary_file != NULL) {
        int numbers[] = {10, 20, 30, 40, 50};
        size_t elements_written = fwrite(numbers, sizeof(int), 5, binary_file);
        printf("Wrote %zu integers to binary file\n", elements_written);
        fclose(binary_file);
    }
    
    binary_file = fopen("data.bin", "rb");
    if (binary_file != NULL) {
        int read_numbers[5];
        size_t elements_read = fread(read_numbers, sizeof(int), 5, binary_file);
        
        printf("Read %zu integers from binary file:\n", elements_read);
        for (int i = 0; i < elements_read; i++) {
            printf("%d ", read_numbers[i]);
        }
        printf("\n");
        
        fclose(binary_file);
    }
    
    printf("\nFile positioning:\n");
    input_file = fopen("output.txt", "r");
    if (input_file != NULL) {
        long pos = ftell(input_file);
        printf("Current position: %ld\n", pos);
        
        fseek(input_file, 10, SEEK_SET);
        pos = ftell(input_file);
        printf("After seeking to 10: %ld\n", pos);
        
        char buffer[50];
        fgets(buffer, sizeof(buffer), input_file);
        printf("Read from position 10: %s", buffer);
        
        rewind(input_file);
        pos = ftell(input_file);
        printf("After rewind: %ld\n", pos);
        
        fclose(input_file);
    }
    
    printf("\nAppending to a file:\n");
    FILE *append_file = fopen("output.txt", "a");
    if (append_file != NULL) {
        fprintf(append_file, "This line was appended.\n");
        fclose(append_file);
        printf("Line appended to output.txt\n");
    }
    
    printf("\nError handling:\n");
    FILE *nonexistent = fopen("nonexistent.txt", "r");
    if (nonexistent == NULL) {
        perror("Error opening nonexistent file");
    }
    
    printf("\nFile information:\n");
    input_file = fopen("output.txt", "r");
    if (input_file != NULL) {
        fseek(input_file, 0, SEEK_END);
        long file_size = ftell(input_file);
        printf("File size: %ld bytes\n", file_size);
        
        fclose(input_file);
    }
    
    printf("\nCleaning up files...\n");
    remove("output.txt");
    remove("data.bin");
    printf("Files cleaned up.\n");
    
    return 0;
}
