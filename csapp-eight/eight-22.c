#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int mysystem(char *commond) {
    int pid, status;
    
    if ((pid = fork()) == 0) {
        char *argv[] = {"", "-c", commond, NULL};
        execve("/bin/sh", argv, environ);
    }
    
    printf("child process pid = %d \n", pid);
    
    if (waitpid(-1, &status, 0) > 0) {
        
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        }
        
        if (WIFSIGNALED(status)) {
            return WTERMSIG(status);
        }
        fprintf(stderr, "command terminated abnormally.\n");
        fprintf(stderr, "return status information...\n");
        return status;
    } else {
        fprintf(stderr, "Failed to reap /bin/sh.\n");
        return EXIT_FAILURE;
    }
    
}

int main(int argc, const char * argv[]) {
    int code;

    code = mysystem("./exit-code");
    printf("normally exit, code: %d\n", code); fflush(stdout);
    
    return 0;
}
