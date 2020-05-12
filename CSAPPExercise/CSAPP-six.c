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

// 6.25
/*
    S   t   s   b
 1. 64  24  6   2
 2. 0   30  0   2
 3. 128 22  7   3
 4. 0   29  0   3
 5. 32  24  5   3
 6. 8   24  3   5
 */

// 6.26
/*
 1. C = 2048  S = 256
 2. B = 4  E = 4
 3. s = 6  b = 1  t = 25
 4. B = 32 b = 5
 */

// 6.27
/*
 s = 3, b = 2, t = 8
 A:
 0x01000101 001 00
 0x01000101 001 01
 0x01000101 001 10
 0x01000101 001 11
 
 0x00111000 001 00
 0x00111000 001 01
 0x00111000 001 10
 0x00111000 001 11
 
 B:
 0x10010001 110 00
 0x10010001 110 01
 0x10010001 110 10
 0x10010001 110 11
 
 0x11110000 110 00
 0x11110000 110 01
 0x11110000 110 10
 0x11110000 110 11
 **/

// 6.28
/*
 A: 0x11101011 010 00
    0x00001010 010 00
 B: 0x11000111 100 00
    0x00000101 100 00
 C: 0x01110001 101 00
    0x01101110 101 00
 D: 0x01000110 111 00
    0x11011110 111 00
 */

// 6.29
/*
 A: s = 2, b = 2, t = 8
 B: NO --
    NO --
    yes C0
 **/

// 6.30
/*
 A: 4 * 4 * 8 = 128
 B: s = 3, b = 2, t = 8
 **/

// 6.31
/*
 A: 0x0 0111 0001 1010
 B: CO:10
    CI:110
    CT:00111000
    是
    0xEB
 **/

// 6.32
/*
 A: 0x1 0110 1110 1000
 B: CO:00
    CI:010
    CT:10110111
    否
    -
 **/

// 6.33
/*
 0x10101100 010 00
 0x10101100 010 01
 0x10101100 010 10
 0x10101100 010 11
 
 0x10100110 010 00
 0x10100110 010 01
 0x10100110 010 10
 0x10100110 010 11
 */

// 6.34
/*
 B = 16; S = 2; E = 1;
 ..00 0 0000  ..10 0 0000
 ..00 0 0100  ..10 1 0000
 ..00 0 1000  ..11 0 0000
 ..00 0 1100  ..11 1 0000
 
 ..00 1 0000  .100 0 0000
 ..00 1 0100  .100 1 0000
 ..00 1 1000  .101 0 0000
 ..00 1 1100  .101 1 0000
 
 dst数组
 列：   0   1   2   3
行：0   m   m   m   m
   1   m   m   m   m
   2   m   m   m   m
   3   m   m   m   m
 
  src数组
  列：   0   1   2   3
 行：0   m   m   h   m
    1   m   h   m   h
    2   m   m   h   m
    3   m   h   m   h
 */

// 6.35
/*
 B = 16; S = 8; E = 1;
 ..000 0000  ..100 0000
 ..000 0100  ..101 0000
 ..000 1000  ..110 0000
 ..000 1100  ..111 0000
 
 ..001 0000  .0 100 0100
 ..001 0100  .0 101 0100
 ..001 1000  .0 110 0100
 ..001 1100  .0 111 0100
 
 ..010 0000  .0 100 0000
 ..010 0100  .0 101 0000
 ..010 1000  .0 110 0000
 ..010 1100  .0 111 0000
 
 ..011 0000  .0 101 0000
 ..011 0100  .0 110 0000
 ..011 1000  .0 111 0000
 ..011 1100  .1 000 0000
 
 dst数组
 列：   0   1   2   3
行：0   m   h   h   h
   1   m   h   h   h
   2   m   h   h   h
   3   m   h   h   h
 
  src数组
  列：   0   1   2   3
 行：0   m   h   h   h
    1   m   h   h   h
    2   m   h   h   h
    3   m   h   h   h
 */

// 6.36
/*
A: E = 1, B = 16, S = 32, 100%
0 00000 0000
1 00000 0000
 
B: E = 1, B = 16, S = 64, 25%
 000000 0000
 100000 0000
 
C: E = 2, B = 16, S = 8, 25%
000 000 0000
100 000 0000
 
 D: NO
 
 E: yes
*/

// 6.37
/*
 E = 1, B = 16, S = 256
 start adress: 0x08000000
 ... 00000000 0000
 
 函数   N=64  N=60
 sumA   25    25
 sumB   100   25
 sumC   50    25
 **/

// 6.38
/*
 E = 1, B = 32, S = 64
 
 A: 1024
 B: 128
 C: 12.5%
 **/

// 6.39
/*
 E = 1, B = 32, S = 64
 
 A: 1024
 B: 256
 C: 25%
 **/

// 6.40
/*
 E = 1, B = 32, S = 64
 
 A: 1024
 B: 256
 C: 25%
 **/
