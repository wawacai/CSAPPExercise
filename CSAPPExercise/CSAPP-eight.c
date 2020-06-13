//
//  CSAPP-eight.c
//  CSAPPExercise
//
//  Created by 彭作青 on 2020/6/10.
//  Copyright © 2020 彭作青. All rights reserved.
//

#include "CSAPP-eight.h"
#include <unistd.h>

// 8.9
/*
 NO YES YES YES YES YES
 **/

// 8.10
/*
 A: setjmp fork
 B: execve longjmp
 C: setjmp fork
 */

// 8.11
// 4次

// 8.12
// 8lines

// 8.13
// 4 3 2

// 8.14
// 3lines

// 8.15
// 5lines

// 8.16
// counter = 2

// 8.17
/*
 hello 0 1 bye 2 bye
 hello 1 0 bye 2 bye
 hello 1 bye 0 2 bye
 **/

// 8.18
// B D

// 8.19
// 2^n

// 8.21
// abc bac

// 8.23
/*
 当父进程C接到信号后，它进入信号处理函数，并暂时将这个信号屏蔽（设置block位），这时子进程还在不断的向父进程发送所有剩下的同类信号，pending位被再次置1，而接下来的信号则会被遗弃（只有一个pending位，没办法计数），当父进程C的信号处理函数退出后，block位被置零，刚刚pending的信号再次被送入父进程C，父进程再次进入信号处理函数，这时子进程已经完成所有的信号发送，所以父进程不会再次进入信号处理函数了。综上，父进程C只会进入两次信号处理函数，即counter只会被加2而非5。
 **/
