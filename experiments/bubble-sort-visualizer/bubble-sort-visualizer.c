#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define BAR_CHAR '#'
#define DELAY_MS 100

// Simple portable delay function
void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + (milliseconds * CLOCKS_PER_SEC / 1000));
}

// Function to clear the console screen
void clearScreen() {
    // Using ANSI escape codes for better portability
    printf("\033[2J\033[H");
    fflush(stdout);
}

// Function to print the array as a horizontal bar chart
void visualizeArray(int arr[], int size, int highlighting1, int highlighting2) {
    clearScreen();
    
    printf("Bubble Sort Visualizer\n");
    printf("======================\n\n");
    
    // Find the maximum value for scaling
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Print the array as bars
    for (int i = 0; i < size; i++) {
        printf("%2d: ", arr[i]);
        
        // Calculate bar length (scale to fit screen)
        int barLength = (arr[i] * 40) / max;
        
        // Set color for highlighting comparisons
        if (i == highlighting1 || i == highlighting2) {
            printf("\033[31m");  // Red color for elements being compared
        }
        
        // Draw the bar
        for (int j = 0; j < barLength; j++) {
            printf("%c", BAR_CHAR);
        }
        
        // Reset color
        printf("\033[0m");
        
        printf("\n");
    }
    printf("\n");
}

// Bubble sort with visualization
void bubbleSortVisualized(int arr[], int size) {
    int swapCount = 0;
    int comparisonCount = 0;
    
    for (int i = 0; i < size - 1; i++) {
        int swapped = 0;
        
        for (int j = 0; j < size - i - 1; j++) {
            comparisonCount++;
            
            // Visualize the comparison
            visualizeArray(arr, size, j, j + 1);
            printf("Comparing: %d and %d\n", arr[j], arr[j + 1]);
            printf("Comparisons: %d, Swaps: %d\n", comparisonCount, swapCount);
            
            delay(DELAY_MS);  // Pause for visualization
            
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
                swapCount++;
                
                // Show the swap
                visualizeArray(arr, size, j, j + 1);
                printf("Swapped: %d and %d\n", arr[j], arr[j + 1]);
                printf("Comparisons: %d, Swaps: %d\n", comparisonCount, swapCount);
                delay(DELAY_MS * 2);  // Longer pause for swaps
            }
        }
        
        // If no swaps occurred, the array is sorted
        if (!swapped) {
            break;
        }
    }
    
    // Final visualization
    visualizeArray(arr, size, -1, -1);
    printf("Array is sorted!\n");
    printf("Total comparisons: %d\n", comparisonCount);
    printf("Total swaps: %d\n", swapCount);
}

// Function to generate random array
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 50 + 1;  // Random numbers between 1 and 50
    }
}

int main() {
    int size;
    int choice;
    
    srand(time(NULL));  // Seed for random number generation
    
    printf("Bubble Sort Visualizer\n");
    printf("======================\n");
    printf("1. Use random array\n");
    printf("2. Enter custom array\n");
    printf("Choice: ");
    scanf("%d", &choice);
    
    printf("Enter array size (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    if (size > MAX_SIZE) {
        size = MAX_SIZE;
    }
    
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    if (choice == 1) {
        generateRandomArray(arr, size);
    } else {
        printf("Enter %d elements:\n", size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
    }
    
    printf("\nPress Enter to start visualization...");
    getchar();  // Clear buffer
    getchar();  // Wait for Enter
    
    // Perform bubble sort with visualization
    bubbleSortVisualized(arr, size);
    
    free(arr);
    
    printf("\nPress Enter to exit...");
    getchar();
    
    return 0;
}
