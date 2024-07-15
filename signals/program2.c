#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
 
void handle_signal(int sig) {
    switch (sig) {
        case SIGINT:
            printf("Received SIGINT (Ctrl+C). Signal number: %d\n", sig);
            break;
        case SIGTERM:
            printf("Received SIGTERM. Signal number: %d. Program will terminate.\n", sig);
            exit(0);  // Terminate the program on SIGTERM
            break;
        default:
            printf("Received unexpected signal: %d\n", sig);
            break;
    }
}
 
int main() {
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sa.sa_flags = 0;
 
    sigemptyset(&sa.sa_mask);
 
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction SIGINT");
        exit(1);
    }
 
    if (sigaction(SIGTERM, &sa, NULL) == -1) {
        perror("sigaction SIGTERM");
        exit(1);
    }
 
    printf("Waiting for SIGINT (Ctrl+C) or SIGTERM signal. Press Ctrl+C or use 'kill -TERM <PID>' to test.\n");
 
    while (1) {
        pause();
    }
    return 0;
}
