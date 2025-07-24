#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to track memory allocations
typedef struct MemoryBlock {
    void *address;
    size_t size;
    char type[20];
    int line;
    struct MemoryBlock *next;
} MemoryBlock;

// Global variables for memory tracking
MemoryBlock *memoryList = NULL;
size_t totalAllocated = 0;
size_t totalFreed = 0;
int allocationCount = 0;
int freeCount = 0;

// Function to add memory allocation to tracking list
void trackAllocation(void *ptr, size_t size, const char *type, int line) {
    if (ptr == NULL) return;
    
    MemoryBlock *newBlock = (MemoryBlock *)malloc(sizeof(MemoryBlock));
    newBlock->address = ptr;
    newBlock->size = size;
    strncpy(newBlock->type, type, sizeof(newBlock->type) - 1);
    newBlock->line = line;
    newBlock->next = memoryList;
    memoryList = newBlock;
    
    totalAllocated += size;
    allocationCount++;
    
    printf("[Line %d] Allocated %zu bytes (%s) at address %p\n", line, size, type, ptr);
}

// Function to remove memory allocation from tracking list
void trackFree(void *ptr, int line) {
    if (ptr == NULL) return;
    
    MemoryBlock *current = memoryList;
    MemoryBlock *prev = NULL;
    
    while (current != NULL) {
        if (current->address == ptr) {
            if (prev == NULL) {
                memoryList = current->next;
            } else {
                prev->next = current->next;
            }
            
            totalFreed += current->size;
            freeCount++;
            printf("[Line %d] Freed %zu bytes at address %p\n", line, current->size, ptr);
            
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    
    printf("[Line %d] WARNING: Attempting to free untracked memory at %p\n", line, ptr);
}

// Function to display memory usage report
void displayMemoryReport() {
    printf("\n========== Memory Usage Report ==========\n");
    printf("Total allocated: %zu bytes\n", totalAllocated);
    printf("Total freed: %zu bytes\n", totalFreed);
    printf("Memory leaked: %zu bytes\n", totalAllocated - totalFreed);
    printf("Allocations: %d\n", allocationCount);
    printf("Frees: %d\n", freeCount);
    
    if (memoryList != NULL) {
        printf("\nLeaked memory blocks:\n");
        MemoryBlock *current = memoryList;
        while (current != NULL) {
            printf("  - %zu bytes (%s) at %p, allocated at line %d\n", 
                   current->size, current->type, current->address, current->line);
            current = current->next;
        }
    } else {
        printf("\nNo memory leaks detected!\n");
    }
    printf("=========================================\n\n");
}

// Wrapper macros for tracking
#define MALLOC(size) trackAllocation(malloc(size), size, "malloc", __LINE__), malloc(size)
#define CALLOC(count, size) trackAllocation(calloc(count, size), (count) * (size), "calloc", __LINE__), calloc(count, size)
#define FREE(ptr) trackFree(ptr, __LINE__), free(ptr)

// Test 1: Basic malloc and free
void testMalloc() {
    printf("\n--- Test 1: Basic malloc and free ---\n");
    
    // Allocate memory for integers
    int *numbers = malloc(5 * sizeof(int));
    trackAllocation(numbers, 5 * sizeof(int), "malloc", __LINE__ - 1);
    
    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Use the allocated memory
    for (int i = 0; i < 5; i++) {
        numbers[i] = i * 10;
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }
    
    // Free the memory
    trackFree(numbers, __LINE__ + 1);
    free(numbers);
}

// Test 2: Calloc (initialized memory)
void testCalloc() {
    printf("\n--- Test 2: Calloc (zero-initialized) ---\n");
    
    // Allocate and initialize memory
    int *zeroArray = calloc(10, sizeof(int));
    trackAllocation(zeroArray, 10 * sizeof(int), "calloc", __LINE__ - 1);
    
    if (zeroArray == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Verify initialization
    printf("Calloc initialized values: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", zeroArray[i]);
    }
    printf("\n");
    
    trackFree(zeroArray, __LINE__ + 1);
    free(zeroArray);
}

// Test 3: Realloc (dynamic resizing)
void testRealloc() {
    printf("\n--- Test 3: Realloc (dynamic resizing) ---\n");
    
    // Initial allocation
    int *dynamicArray = malloc(3 * sizeof(int));
    trackAllocation(dynamicArray, 3 * sizeof(int), "malloc", __LINE__ - 1);
    
    if (dynamicArray == NULL) {
        printf("Initial allocation failed!\n");
        return;
    }
    
    // Fill initial array
    for (int i = 0; i < 3; i++) {
        dynamicArray[i] = i + 1;
    }
    
    printf("Original array (size 3): ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");
    
    // Resize the array
    trackFree(dynamicArray, __LINE__ + 1);  // Track the old memory being freed
    int *temp = realloc(dynamicArray, 6 * sizeof(int));
    
    if (temp == NULL) {
        printf("Reallocation failed!\n");
        free(dynamicArray);
        return;
    }
    
    dynamicArray = temp;
    trackAllocation(dynamicArray, 6 * sizeof(int), "realloc", __LINE__ - 2);
    
    // Add new elements
    for (int i = 3; i < 6; i++) {
        dynamicArray[i] = i + 1;
    }
    
    printf("Resized array (size 6): ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");
    
    trackFree(dynamicArray, __LINE__ + 1);
    free(dynamicArray);
}

// Test 4: Memory leak demonstration
void testMemoryLeak() {
    printf("\n--- Test 4: Memory leak demonstration ---\n");
    
    // Intentionally create a memory leak
    char *leakedMemory = malloc(100);
    trackAllocation(leakedMemory, 100, "malloc", __LINE__ - 1);
    
    strcpy(leakedMemory, "This memory will be leaked!");
    printf("Allocated string: %s\n", leakedMemory);
    printf("WARNING: Intentionally not freeing this memory!\n");
    
    // Memory is not freed - this is a leak!
}

// Test 5: Dynamic 2D array
void test2DArray() {
    printf("\n--- Test 5: Dynamic 2D array ---\n");
    
    int rows = 3, cols = 4;
    
    // Allocate array of pointers
    int **matrix = malloc(rows * sizeof(int *));
    trackAllocation(matrix, rows * sizeof(int *), "malloc", __LINE__ - 1);
    
    if (matrix == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Allocate each row
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        trackAllocation(matrix[i], cols * sizeof(int), "malloc", __LINE__ - 1);
        
        if (matrix[i] == NULL) {
            printf("Row allocation failed!\n");
            // Free previously allocated rows
            for (int j = 0; j < i; j++) {
                trackFree(matrix[j], __LINE__ + 1);
                free(matrix[j]);
            }
            trackFree(matrix, __LINE__ + 1);
            free(matrix);
            return;
        }
    }
    
    // Fill and display the matrix
    printf("2D Array (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j;
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Free the 2D array (proper order)
    for (int i = 0; i < rows; i++) {
        trackFree(matrix[i], __LINE__ + 1);
        free(matrix[i]);
    }
    trackFree(matrix, __LINE__ + 1);
    free(matrix);
}

// Test 6: Memory fragmentation simulation
void testFragmentation() {
    printf("\n--- Test 6: Memory fragmentation simulation ---\n");
    
    void *blocks[10];
    size_t sizes[] = {64, 128, 32, 256, 16, 512, 128, 64, 32, 1024};
    
    // Allocate various sized blocks
    printf("Allocating blocks of various sizes...\n");
    for (int i = 0; i < 10; i++) {
        blocks[i] = malloc(sizes[i]);
        trackAllocation(blocks[i], sizes[i], "malloc", __LINE__ - 1);
    }
    
    // Free every other block (creates fragmentation)
    printf("\nFreeing alternate blocks (creating fragmentation)...\n");
    for (int i = 0; i < 10; i += 2) {
        trackFree(blocks[i], __LINE__ + 1);
        free(blocks[i]);
        blocks[i] = NULL;
    }
    
    // Try to allocate a large block
    printf("\nAttempting to allocate a large block (2048 bytes)...\n");
    void *largeBlock = malloc(2048);
    if (largeBlock != NULL) {
        trackAllocation(largeBlock, 2048, "malloc", __LINE__ - 2);
        printf("Large block allocation successful!\n");
        trackFree(largeBlock, __LINE__ + 1);
        free(largeBlock);
    } else {
        printf("Large block allocation failed (fragmentation issue)!\n");
    }
    
    // Clean up remaining blocks
    printf("\nCleaning up remaining blocks...\n");
    for (int i = 1; i < 10; i += 2) {
        if (blocks[i] != NULL) {
            trackFree(blocks[i], __LINE__ + 1);
            free(blocks[i]);
        }
    }
}

int main() {
    printf("Memory Allocation Test Suite\n");
    printf("============================\n");
    printf("This program demonstrates various memory allocation techniques in C\n");
    printf("and tracks memory usage to detect leaks.\n");
    
    // Run all tests
    testMalloc();
    testCalloc();
    testRealloc();
    testMemoryLeak();
    test2DArray();
    testFragmentation();
    
    // Display final memory report
    displayMemoryReport();
    
    // Clean up the memory tracking list
    MemoryBlock *current = memoryList;
    while (current != NULL) {
        MemoryBlock *next = current->next;
        free(current);
        current = next;
    }
    
    printf("Press Enter to exit...");
    getchar();
    
    return 0;
}
