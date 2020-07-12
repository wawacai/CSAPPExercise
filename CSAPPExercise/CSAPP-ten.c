//
//  CSAPP-ten.c
//  CSAPPExercise
//
//  Created by 彭作青 on 2020/7/12.
//  Copyright © 2020 彭作青. All rights reserved.
//

#include "CSAPP-ten.h"
#include "csapp.h"

// 10.6
// 4

// 10.7

void ten_cfile() {
    size_t n;
    int buf[MAXBUF];
    
    while ((n = rio_readn(STDIN_FILENO, buf, MAXBUF)) != 0) {
        Rio_writen(STDOUT_FILENO, buf, n);
    }
}

