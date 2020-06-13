#include "csapp.h"

#define N 2

int main() {
    int status, i;
    pid_t pid;
    
    for (i = 0; i < N; i++) {
        
        if (fork() == 0) {
            int *p = 0;
            *p = 0;
        }
    }
    
    while ((pid = waitpid(-1, &status, 0)) > 0) {
        if (WIFEXITED(status)) {
            printf("child %d terminated normally with exit status = %d", pid, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            char buf[100];
            sprintf(buf, "child %d terminated by signal %d", pid, WTERMSIG(status));
            psignal(WTERMSIG(status), buf);
        } else {
            fprintf(stderr, "child %d terminated abnormally with status information=%d\n"
            , pid, status);
        }
    }
    
    if (errno != ECHILD) {
        fprintf(stderr, "waitpid error");
    }
    
    return 0;
}
