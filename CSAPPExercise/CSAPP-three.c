//
//  CSAPP-three.c
//  CSAPPExercise
//
//  Created by 彭作青 on 2020/1/8.
//  Copyright © 2020 彭作青. All rights reserved.
//

#include "CSAPP-three.h"

void three_twoDecode1(long *xp, long * yp, long *zp) {
    /*
     read *xp to %r8
     read *yp to %rcx
     read *zp to %rax
     */
    long a = *xp;
    long b = *yp;
    long c = *zp;
    *yp = a;
    *zp = b;
    *xp = c;
}

/// 3.58
long three_decode2(long x, long y, long z) {
    long a = z + y;
    long b = a * x;
    a = a << 63;
    a = a >> 63;
    return b ^ a;
}

typedef __int128 int128_t;
/// 3.59
void three_store_prod(int128_t *dest, int64_t x, int64_t y) {
    *dest = x * (int128_t)y;
    /*
     %rax = y
     
     %rcx = x >> 63
     %rcx = (x >> 63) * y;
     %rdx = y * x
     %rcx = (x >> 63) * y + y * x
     %rsi = x * x
     %rdx = y * ((x >> 63) * y + y * x)
     *dest = y
     
     */
}

