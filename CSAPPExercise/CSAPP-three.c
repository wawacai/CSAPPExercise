//
//  CSAPP-three.c
//  CSAPPExercise
//
//  Created by 彭作青 on 2020/1/8.
//  Copyright © 2020 彭作青. All rights reserved.
//

#include "CSAPP-three.h"
#include <stdio.h>
#include <string.h>

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

/// 3.63
long three_switch_prob(long x, long n) {
    long result = x;
    switch (n) {
        case 60:
        case 62:
            result *= 8;
            break;
        case 63:
            result /= 8;
            break;
        case 64:
            result *= 15;
            x = result;
        case 65:
            x = x^2;
        default:
            result += 75;
            break;
    }
    return result;
    /*
     0011 1100  60
     0100 1011  75
     */
}

// 3.64
/*
  A: Xa + 8 * T * (S * i + j) + 8 * k
 TS = 65
 T = 13
 TSR + TS = 455
 T = 13
 S = 5
 R = 6
 65R + 65 = 455
 */

// 3.65
/*
 A: %rdx
 B: %rax
 C: M = 15
 */

// 3.66
/*
 NR: 3n
 NC: 1 + 4n
 */

// 3.67
/*
 当调用一个函数时,%rsp会减去8来存一个返回地址
 B: 栈指针
 C: 栈指针偏移
 D: 通过所传的表示栈地址的参数,来间接存储在栈上
 F: 传递结构体这样不能用一个寄存器保存的类型，用指针来代替
 */

// 3.68
/*
 172 < 4 * A * B <= 184
 43 <= A * B <= 46
 5 <= B <= 8
 3 <= A <= 10
 B = 5 , A = 9
 */

// 3.69
/*
 1 0010 0000  288
 281 <=  <= 284
 
 A: 7
 B:  struct {
    long idx;
    long x[4];
 }
 */

// 3.70
/*
 A: 0 8 0 8
 B: 16
 */

union ele {
    struct {
        long *p;
        long y;
    } e1;
    struct {
        long x;
        union ele *next;
    } e2;
};

void three_proc(union ele *up) {
    up->e2.x = *(up->e2.next->e1.p) - up->e2.next->e1.y;
}

/// 3.71
void three_good_echo() {
    const int bufferSize = 8;
    char str[bufferSize];
    printf("start\n");
    
    while (1) {
        fgets(str, bufferSize, stdin);
        
        if (strlen(str) == bufferSize - 1) {
            fputs(str, stdout);
            
            if (str[bufferSize-1-1] == '\n') {
                break;
            }
            memset(str, 0, bufferSize);
        } else if (strlen(str) < bufferSize - 1) {
            fputs(str, stdout);
            break;
        } else {
            break;
        }
    }
    printf("end\n");
    return;
}

// 3.72
/*
 s1 = %rsp - 16
 s2 = s1 - (8n + 30) & -16
 p = (s2 + 15) & -16
 */

// 3.73
typedef enum {NEG, ZERO, POS, OTHER} range_t;

/*
 find_range:
    vxorps %xmm1, %xmm1, %xmm1
    vucomiss %xmm0, %xmm1
    jp .L1
    ja .L2
    jb .L3
    je .L4
 .L2:
    movl $2, %eax
    jmp .Done
 .L3:
    movl $0, %eax
    jmp .Done
 .L4:
    movl $1, %eax
    jmp .Done
 .L1:
    movl $3, %eax
 .Done
    rep; ret
    
 */

// 3.74
/*
find_range:
   vxorps %xmm1, %xmm1, %xmm1
   vucomiss %xmm0, %xmm1
   cmova $0, %eax
   cmove $1, %eax
   cmovb $2, %eax
   cmovp $3, %eax
   rep; ret
*/
