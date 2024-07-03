#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed");
        exit(1);
    }
    else if (pid == 0) {
        printf("(C) Child is having ID %d\n", (int) getpid());
        printf("(D) My  ID is %d\n", (int) getpid());
        
    } else {
        printf("(A) Parent (P) is having ID %d\n", (int) getpid());
        wait(NULL);
        printf("(B) ID of P's Child is %d\n", (int) getpid());
    }

    return 0;
}
