#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
 
void handle_sigint(int sig) {
    printf("hello world!!!!!\n");
}
 
int main() {
    if (signal(SIGINT, handle_sigint) == SIG_ERR) {
        perror("signal");
        exit(1);
    }
 
    printf("Press Ctrl+C to send SIGINT signal.\n");
    while (1) {
        sleep(1);
    }
 
    return 0;
}
