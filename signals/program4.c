#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
 
void handle_sigint(int sig) {
    printf("\nHello world!!!!!!\n");
}
 
int main() {
    sigset_t new_mask, old_mask;
 
    // Initialize the signal set to empty
    sigemptyset(&new_mask);
 
    // Add SIGINT to the signal set
    sigaddset(&new_mask, SIGINT);
 
    if (signal(SIGINT, handle_sigint) == SIG_ERR) {
        perror("signal");
        exit(1);
    }
 
    printf("SIGINT signal is blocked for 10 seconds. Press Ctrl+C during this time to test.\n");
 
    // Block SIGINT signal
    if (sigprocmask(SIG_BLOCK, &new_mask, &old_mask) == -1) {
        perror("sigprocmask");
        exit(1);
    }
 
    sleep(10);
 
    printf("10 seconds have passed. SIGINT signal is now unblocked. Press Ctrl+C to test.\n");
 
    // Unblock SIGINT signal
    if (sigprocmask(SIG_SETMASK, &old_mask, NULL) == -1) {
        perror("sigprocmask");
        exit(1);
    }
 
    while (1) {
   sleep(1);
    }
 
    return 0;
}
