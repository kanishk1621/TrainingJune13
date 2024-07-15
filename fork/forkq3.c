#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CHILDREN 10

// Function to compute the sum of a portion of the array
void compute_sum(int start, int end, int *array, long *result) {
    *result = 0;
    for (int i = start; i < end; i++) {
        *result += array[i];
    }
}

int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <size_of_array> <element1> <element2> ... <elementN>\n", argv[0]);
        return 1;
    }

    // Parse the size of the array
    int size = atoi(argv[1]);
    if (size <= 0 || size != argc - 2) {
        fprintf(stderr, "Array size mismatch or invalid size.\n");
        return 1;
    }

    // Create the array from command-line arguments
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        array[i] = atoi(argv[i + 2]);
    }

    // Determine the number of child processes to create
    int num_children = (size < MAX_CHILDREN) ? size : MAX_CHILDREN;
    int chunk_size = size / num_children;
    int remainder = size % num_children;

    // Array to store child process IDs
    pid_t child_pids[num_children];

    // Fork the child processes
    for (int i = 0; i < num_children; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            free(array);
            return 1;
        }

        if (pid == 0) {
            // Child process
            int start = i * chunk_size + ((i < remainder) ? i : remainder);
            int end = start + chunk_size + ((i < remainder) ? 1 : 0);
            long partial_sum;
            compute_sum(start, end, array, &partial_sum);
            printf("Child %d: Start=%d, End=%d, Partial Sum=%ld\n", i, start, end, partial_sum);
            exit(partial_sum);
        } else {
            // Parent process
            child_pids[i] = pid;
        }
    }

    // Parent process waits for all children to terminate and collects results
    long total_sum = 0;
    for (int i = 0; i < num_children; i++) {
        int status;
        waitpid(child_pids[i], &status, 0);
        if (WIFEXITED(status)) {
            total_sum += WEXITSTATUS(status);
        } else {
            fprintf(stderr, "Child %d did not terminate normally\n", i);
        }
    }

    // Print the final result
    printf("Total Sum: %ld\n", total_sum);

    // Clean up
    free(array);
    return 0;
}

