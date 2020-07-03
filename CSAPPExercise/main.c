//
//  main.c
//  CSAPPExercise
//
//  Created by 彭作青 on 2019/12/21.
//  Copyright © 2019 彭作青. All rights reserved.
//

#include <stdio.h>
#include "CSAPP-two.h"
#include "CSAPP-three.h"
#include "csapp.h"
#include "CSAPP-eight.h"

void handle_test(int sig) {
    int oldErr = errno;
    pid_t pid;
    
    while ((pid = waitpid(-1, NULL, 0)) > 0) {
        printf("child is exit %d\n", pid);
    }
    
    sleep(1);
    if (errno != ECHILD) {
        printf("errno");
    }
    errno = oldErr;
}

int main(int argc, const char * argv[]) {
    
    int fp = open("/Users/pengzuoqing/Desktop/openFile.txt", O_RDWR, 0);
    struct stat testStat;
    
    fstat(fp, &testStat);
    int *buf = mmap(NULL, testStat.st_size, PROT_WRITE, MAP_PRIVATE, fp, 0);
//    (char *)*buf = "jello,world.\n";
    char *first = (char *)buf;
    first[0] = 'd';
    printf("%s\n", (char *)buf);
    size_t result = write(fp, buf,1);
    printf("%ld \n", result);
//     callTwoFunction();
    // insert code here...
//    printf("Hello, World!\n");
//    three_good_echo();

//    printf("%d", a);
    
//    for (int i = 0; argv[i] != NULL; i++) {
//        printf("argv[%d] = %s \n", i, argv[i]);
//    }
//    char s[100];
//    printf("start \n");
//    char *retS = tfgets(s, 100, stdin);
//    printf("%s", retS);
    
//    int a = 1;
//    int *c[] = {&a};
//    int **d = c;
//    printf(" d = %p \n c = %p\n &c = %p \n &a = %p \n c[0] = %p \n *c[0] = %d \n", d, c, &c, &a, c[0], *c[0]);
    
//    int i;
//
//    if (signal(SIGCHLD, handle_test) == SIG_ERR) {
//        printf("sig_err");
//    }
//
//    for (i = 0; i < 3; i++) {
//        if (fork() == 0) {
//            printf("hello from child %d\n ", getpid());
//            exit(0);
//        }
//    }
//
//    printf("parent handle\n®");
//
//    while (1) {
//
//    }
    
    return 0;
}
