
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, const char * argv[], const char *envp[]) {
    
    if (execve("/bin/ls", argv, envp)) {
        perror("failed to execve");
    }
    
    return 0;
}
