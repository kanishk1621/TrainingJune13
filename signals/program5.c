#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
 
// Signal handler function for SIGALRM
void handle_sigalrm(int sig) {
    printf("Received SIGALRM signal. Alarm went off!\n");
}
 
int main() {
    // Register the signal handler for SIGALRM
    struct sigaction sa;
    sa.sa_handler = handle_sigalrm;
    sa.sa_flags = 0;  // No special flags
    sigemptyset(&sa.sa_mask);  // No additional signals are blocked during the handler
 
    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }
 
    alarm(5);
 
    printf("Alarm is set for 5 seconds. Waiting for SIGALRM signal...\n");
 
    while (1) {
        pause();
    }
 
    return 0;
}
