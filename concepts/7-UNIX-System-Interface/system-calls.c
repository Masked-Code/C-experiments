#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    printf("UNIX System Interface - System Calls:\n\n");
    
    printf("Low-level file operations:\n");
    
    int fd = open("test_file.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    
    char *message = "Hello from system call!\n";
    ssize_t bytes_written = write(fd, message, strlen(message));
    printf("Wrote %zd bytes to file\n", bytes_written);
    
    close(fd);
    
    fd = open("test_file.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file for reading");
        return 1;
    }
    
    char buffer[100];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    buffer[bytes_read] = '\0'; 
    
    printf("Read %zd bytes: %s", bytes_read, buffer);
    close(fd);
    
    printf("\nFile status information:\n");
    struct stat file_stat;
    if (stat("test_file.txt", &file_stat) == 0) {
        printf("File size: %lld bytes\n", (long long)file_stat.st_size);
        printf("File permissions: %o\n", file_stat.st_mode & 0777);
        printf("Number of links: %ld\n", (long)file_stat.st_nlink);
    }
    
    printf("\nProcess information:\n");
    printf("Process ID: %d\n", getpid());
    printf("Parent Process ID: %d\n", getppid());
    printf("User ID: %d\n", getuid());
    printf("Group ID: %d\n", getgid());
    
    printf("\nWorking directory:\n");
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("getcwd failed");
    }
    
    printf("\nEnvironment variables:\n");
    char *home = getenv("HOME");
    if (home != NULL) {
        printf("HOME: %s\n", home);
    }
    
    char *path = getenv("PATH");
    if (path != NULL) {
        printf("PATH: %.50s...\n", path); 
    }
    
    printf("\nCommand execution:\n");
    printf("Executing 'date' command:\n");
    int result = system("date");
    printf("Command returned: %d\n", result);
    
    printf("\nFile permissions:\n");
    if (chmod("test_file.txt", 0755) == 0) {
        printf("Changed file permissions to 755\n");
    } else {
        perror("chmod failed");
    }
    
    printf("\nFile access checks:\n");
    if (access("test_file.txt", F_OK) == 0) {
        printf("File exists\n");
    }
    if (access("test_file.txt", R_OK) == 0) {
        printf("File is readable\n");
    }
    if (access("test_file.txt", W_OK) == 0) {
        printf("File is writable\n");
    }
    if (access("test_file.txt", X_OK) == 0) {
        printf("File is executable\n");
    }
    
    printf("\nDirectory operations:\n");
    if (mkdir("test_dir", 0755) == 0) {
        printf("Created directory 'test_dir'\n");
        
        if (rmdir("test_dir") == 0) {
            printf("Removed directory 'test_dir'\n");
        } else {
            perror("rmdir failed");
        }
    } else {
        perror("mkdir failed");
    }
    
    printf("\nCleaning up...\n");
    if (unlink("test_file.txt") == 0) {
        printf("Removed test_file.txt\n");
    } else {
        perror("unlink failed");
    }
    
    return 0;
}
