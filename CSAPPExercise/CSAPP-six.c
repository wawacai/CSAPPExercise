//
//  CSAPP-six.c
//  CSAPPExercise
//
//  Created by 彭作青 on 2020/5/4.
//  Copyright © 2020 彭作青. All rights reserved.
//

#include "CSAPP-six.h"

// 6.22
/*
 C = x * r * 2 * (1-x) * r
    x-x^2 最大，则x=0.5
 */

// 6.23
/*
 Tr = 60 / 15000 * 1000 * 0.5 = 2ms
 Tt = 60 / 15000 * 1 / 800 * 1000 = 0.005ms
 Ta = Ts + Tr + Tt = 6.005ms
 */

// 6.24
/*
 Tr = 2ms
 Tt = 60 / 15000 * 1 / 1000 * 1000 = 0.004ms
 Ta = 6.004ms
 
 A: 4* 1024 = 4096个扇区，4个磁道，6 + 4 * 4 = 22
 B: 4096 * 6.004 = 24592ms
 */
