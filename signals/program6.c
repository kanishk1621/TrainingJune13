#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
 
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
        exit(1);
    }
 
    pid_t target_pid = atoi(argv[1]);  // Get the target PID from command-line arguments
 
    if (kill(target_pid, SIGUSR1) == -1) {  // Send SIGUSR1 signal to the target process
        perror("kill");
        exit(1);
    }
 
    printf("SIGUSR1 signal sent to process %d\n", target_pid);
 
    return 0;
}
