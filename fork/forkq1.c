#include <stdio.h>
#include <unistd.h> 

int main() {
    // Create a child process
    pid_t pid = fork();

    // Check if fork() was successful
    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // This is the child process
        printf("Hello from child!\n");
    } else {
        // This is the parent process
        printf("Hello from parent!\n");
    }

    return 0;
}

