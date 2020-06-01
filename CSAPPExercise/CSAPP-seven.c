//
//  CSAPP-seven.c
//  CSAPPExercise
//
//  Created by 彭作青 on 2020/6/1.
//  Copyright © 2020 彭作青. All rights reserved.
//

#include "CSAPP-seven.h"

// 7.6
/*
 符号
 buf    YES      外部      m.o     .data
 bufp0  YES     GLOBLE   swap.o   .data
 bufp1  YES     局部      swap.o   .bss
 swap   YES     GLOBLE   swap.o    .text
 temp   NO      --       --         --
 incr   YES     局部      swap.o    .text
 count  YES     局部      swap.o   .bss
 **/
