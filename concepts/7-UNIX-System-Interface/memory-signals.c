#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void signal_handler(int sig) {
    printf("Received signal %d\n", sig);
    if (sig == SIGINT) {
        printf("Caught SIGINT (Ctrl+C)\n");
    } else if (sig == SIGTERM) {
        printf("Caught SIGTERM\n");
    }
}

int main() {
    printf("UNIX System Interface - Memory and Signals:\n\n");
    
    printf("Dynamic memory allocation:\n");
    
    int *numbers = (int *)malloc(5 * sizeof(int));
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
    
    numbers = (int *)realloc(numbers, 10 * sizeof(int));
    if (numbers == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }
    
    for (int i = 5; i < 10; i++) {
        numbers[i] = i * 10;
    }
    
    printf("Expanded array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    free(numbers);
    printf("Memory freed\n");
    
    printf("\nSignal handling:\n");
    
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    
    printf("Signal handlers set up\n");
    printf("Press Ctrl+C to test SIGINT handler\n");
    
    pid_t pid = fork();
    
    if (pid == 0) {
        printf("Child process sleeping...\n");
        sleep(2);
        printf("Child process waking up\n");
        exit(0);
    } else if (pid > 0) {
        printf("Parent process waiting for child...\n");
        
        int status;
        wait(&status);
        
        if (WIFEXITED(status)) {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        }
    } else {
        perror("fork failed");
        return 1;
    }
    
    printf("\nSending SIGTERM to self...\n");
    kill(getpid(), SIGTERM);
    
    sleep(1);
    
    printf("\nMemory operations:\n");
    
    int *zero_array = (int *)calloc(5, sizeof(int));
    if (zero_array != NULL) {
        printf("Zeroed array: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", zero_array[i]);
        }
        printf("\n");
        free(zero_array);
    }
    
    char *str1 = (char *)malloc(20);
    char *str2 = (char *)malloc(20);
    
    if (str1 && str2) {
        strcpy(str1, "Hello");
        strcpy(str2, "World");
        
        int cmp = memcmp(str1, str2, 5);
        printf("Memory comparison result: %d\n", cmp);
        
        memcpy(str2, str1, 5);
        printf("After memcpy: %s\n", str2);
        
        memset(str1, 'X', 3);
        str1[3] = '\0';
        printf("After memset: %s\n", str1);
        
        free(str1);
        free(str2);
    }
    
    printf("\nProgram completed\n");
    return 0;
}
