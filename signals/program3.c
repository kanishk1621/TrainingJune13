#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
 
int main() {
    if (signal(SIGINT, SIG_IGN) == SIG_ERR) {
        perror("signal");
        exit(1);
    }
 
    printf("SIGINT signal is now being ignored. Press Ctrl+C to test.\n");
 
    while (1) {
        sleep(1);
    }
 
    return 0;
}
