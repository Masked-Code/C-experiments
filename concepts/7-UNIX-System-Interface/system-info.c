#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>

int main() {
    printf("UNIX System Program - System Information:\n\n");
    
    struct utsname sysinfo;
    if (uname(&sysinfo) == 0) {
        printf("System name: %s\n", sysinfo.sysname);
        printf("Node name: %s\n", sysinfo.nodename);
        printf("Release: %s\n", sysinfo.release);
        printf("Version: %s\n", sysinfo.version);
        printf("Machine: %s\n", sysinfo.machine);
    }
    
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("Hostname: %s\n", hostname);
    }

    printf("Sleeping for 1 second...\n");
    sleep(1);

    pid_t pid = fork();
    if (pid == 0) {
        printf("This is the child process with PID: %d\n", getpid());
    } else if (pid > 0) {
        printf("This is the parent process with PID: %d\n", getpid());
        printf("Child process PID: %d\n", pid);
    } else {
        printf("Forking failed!\n");
    }

    return 0;
}

