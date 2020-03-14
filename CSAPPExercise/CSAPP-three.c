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

/// 3.60
long loop(long x, int n) {
    long result = 0;
    long mask;
    
    for (mask = 1; mask != 0; mask = mask << n %256) {
        result = result | (x & 1);
    }
    return result;
}

/// 3.61
long three_create_alt(long *xp) {
    long t = 0;
    long *p = xp ? xp : &t;
    return *p;
}

typedef enum {MODE_A, MODE_B, MODE_C, MODE_D, MODE_E} mode_p;
/// 3.62
long three_switch3(long *p1, long *p2, mode_p action) {
    long result = 0;
    switch (action) {
        case MODE_A:
            result = *p2;
            *p2 = *p1;
            break;
        case MODE_B:
            result = *p1;
            result += *p2;
            *p1 = result;
            break;
        case MODE_C:
            *p1 = 59;
            result = *p2;
            break;
        case MODE_D:
            result = *p2;
            *p1 = result;
            result = 27;
            break;
        case MODE_E:
            result = 27;
            break;
        default:
            result = 12;
            break;
    }
    return result;
}

