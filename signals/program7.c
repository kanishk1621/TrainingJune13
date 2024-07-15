#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void handle_sigint(int sig) {
    printf("Received SIGINT (Ctrl+C). Signal number: %d\n", sig);
    printf("SIGTERM is blocked during SIGINT handler execution.\n");
    sleep(5);
    printf("SIGINT handler is done.\n");
}
 
void handle_sigterm(int sig) {
    printf("Received SIGTERM. Signal number: %d\n", sig);
}
 
int main() {
    struct sigaction sa_int, sa_term;
 
    // Setup SIGINT handler
    sa_int.sa_handler = handle_sigint;
    sa_int.sa_flags = 0;  // No special flags
    sigemptyset(&sa_int.sa_mask);  // No signals blocked during the handler
    sigaddset(&sa_int.sa_mask, SIGTERM);  // Block SIGTERM during SIGINT handler
 
    if (sigaction(SIGINT, &sa_int, NULL) == -1) {
        perror("sigaction for SIGINT");
        exit(1);
    }
 
    // Setup SIGTERM handler
    sa_term.sa_handler = handle_sigterm;
    sa_term.sa_flags = 0;
    sigemptyset(&sa_term.sa_mask);  // No additional signals are blocked during the handler
 
    if (sigaction(SIGTERM, &sa_term, NULL) == -1) {
        perror("sigaction for SIGTERM");
        exit(1);
    }
 
    printf("Signal handlers are set up.\n");
    printf("Send SIGINT (Ctrl+C) or SIGTERM using the kill command.\n");
  while (1) {
        pause();
    }
 
    return 0;
}
