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

int main(int argc, const char * argv[]) {
//     callTwoFunction();
    // insert code here...
//    printf("Hello, World!\n");
//    three_good_echo();

//    printf("%d", a);
    
//    for (int i = 0; argv[i] != NULL; i++) {
//        printf("argv[%d] = %s \n", i, argv[i]);
//    }
    char s[100];
    printf("start \n");
    char *retS = tfgets(s, 100, stdin);
    printf("%s", retS);
    return 0;
}
