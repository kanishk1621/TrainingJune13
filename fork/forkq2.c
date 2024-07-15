#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_children>\n", argv[0]);
        return 1;
    }

    // Convert the argument to an integer
    int n = atoi(argv[1]);

    // Validate the number of children
    if (n <= 0) {
        fprintf(stderr, "The number of children must be a positive integer.\n");
        return 1;
    }

    // Array to store child PIDs
    pid_t child_pids[n];

    // Create n child processes
    for (int i = 0; i < n; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            // Fork failed
            perror("fork failed");
            return 1;
        }

        if (pid == 0) {
            // Child process
            printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
            exit(0);  // Child exits after printing
        } else {
            // Parent process
            child_pids[i] = pid;  // Store the PID of the child process
        }
    }

    // Parent waits for all children to terminate
    for (int i = 0; i < n; i++) {
        int status;
        waitpid(child_pids[i], &status, 0);  // Wait for each specific child
    }

    // Print message after all children have terminated
    printf("All children have terminated.\n");

    return 0;
}

