//
//  CSAPP-two.c
//  CExerciseDemoSet
//
//  Created by 彭作青 on 2019/12/13.
//  Copyright © 2019 彭作青. All rights reserved.
//

#include "CSAPP-two.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef unsigned char *two_byte_pointer;

void two_show_bytes(two_byte_pointer start, size_t len) {
    size_t i;
    
    for (i = 0; i < len; i++) {
        printf("%.2x ", start[i]);
    }
    printf("\n");
}

void two_show_int(int x) {
    two_show_bytes((two_byte_pointer) &x, sizeof(int));
}

void two_show_short(short sh) {
    two_show_bytes((two_byte_pointer)&sh, sizeof(short));
}
 
void two_show_long(long lo) {
    two_show_bytes((two_byte_pointer)&lo, sizeof(long));
}

void two_islittle_endian() {
    int aa = 0x1;
    
    two_byte_pointer point = (two_byte_pointer)&aa;
    
    int first = point[0];
    
    if (first == 0x01) {
        printf("1 \n");
    } else {
        printf("0 \n");
    }
}

/// 2.59
void two_combination(int x, int y) {
    int xLow = x&0xff;
    printf("%x \n", xLow);
    int yHight = (y>>8)<<8;
    printf("%x \n", yHight);
    int comNumb = xLow|yHight;
    printf("%x \n", comNumb);
}

/// 2.60
void two_replace_byte(unsigned x, int i, unsigned char b) {
    unsigned a = x>>(i*8);
    unsigned leftA = a<<24;
    unsigned rightA = leftA>>((3-i)*8);
    rightA = x - rightA;
    unsigned tempB = b;
    tempB = tempB<<(i*8);
    printf("%x \n", tempB + rightA);
}

/// 2.61
int two_judgeInt(int x) {
    int result1 = !x;
    
    int result2 = !(x+1);
    
    int leftX = (x+1)<<((sizeof(int)-1)<<3);
    int result3 = !leftX;
    
    int rightX = x>>((sizeof(int)-1)<<3);
    int result4 = !rightX;
    
    return result1 || result2 || result3 || result4;
}

/// 2.62
int two_int_shifts_are_arithmetic() {
    int num = -1;
    int result = num>>((sizeof(int)<<3) - 1);
    return !(result+1);
}

/// 2.63
unsigned srl(unsigned x, int k) {
    unsigned xsra = (int)x >> k;
    int result = -1&&k;
    int left = (-result)<<(sizeof(int)*8-k);
    
    printf("%x\n",left);
//    printf("%x\n",xsra);
    return (xsra|left)^left;
}

/// 2.63
int sra(int x, int k) {
    int xsrl = (unsigned)x>>k;
    int oneLeft = 1<<(sizeof(int)*8-k-1);
    int high = oneLeft & xsrl;
    int result = high && k;
    int leftValue = (-result)<<(sizeof(int)*8-k);
    return leftValue^xsrl;
}

/// 2.64
int two_any_odd_one(unsigned x) {
    unsigned oddOne = 0b10101010101010101010101010101010;
    int result = oddOne & x;
    return result && 1;
}

// MARK: - 没有做出来 2.66
/// 2.66
int two_leftmost_one(unsigned x) {
    return 1;
}

typedef int32_t myInt;

/// 2.67
int two_int_size_is_32() {
    // B：至少在32位上能运行
//    int set_msb = 1 << 31;
//    int beyond_msb = set_msb >> 31;
//    beyond_msb += 1;
//
//    return set_msb && !beyond_msb;
    
    // C:至少在16位上能运行
    myInt set_msb = 1 << 15;
    set_msb = set_msb + set_msb;
    myInt result = set_msb << 15;
    myInt twoResult = result + result;
    return result && !twoResult;
}

/// 2.68
int two_lower_one_mask(int n) {
    unsigned c = -1;
    int d = (c >> (31-n)) >> (n && 1);
    return d;
}

/// 2.69
unsigned two_rotate_left(unsigned x, int n) {
    unsigned a = x << n;
    n = n-1;
    unsigned b = (x >> (31-n)) >> (n && 1);
    return a+b;
}

/// 2.70
int two_fits_bits(int x, int n) {
    int a = x >> (n-1);
    return (a == 0) || (a == -1);
}

typedef unsigned packed_t;
/// 2.71
int xbyte(packed_t word, int byttenum) {
    int a = word << (32 - ((byttenum + 1) << 3));
    return a >> 24;
}

/// 2.72
void two_copy_int(int val, void *buf, int maxbytes) {
    if (maxbytes >= sizeof(val)) {
        memcpy(buf, (void *)&val, sizeof(val));
    }
}

/// 2.73
int two_saturating_add(int x, int y) {
    int w = (sizeof(int) << 3) - 1;
    int mark1 = ~(x ^ y) >> w;
    int mark2 = ((x + y) ^ y) >> w;
    int mark = !(mark1 && mark2);
    
    int sum = x + y;
//    int result = (sum - y) == x;
    
    unsigned temX = x;
    temX = temX >> 31;
    
    unsigned a = -1;
    a = a >> 1;
    printf("a = %x \n", a);
//    int c1 = (sum & (-result));
//    printf("c1 = %x \n", c1);
//    int c2 = ((-(-result+1) >> 1) + (!result && (temX ^ 0)));
//    printf("c2 = %x \n", c2);
    
    return (sum & (-mark)) | (a + (!mark && (temX ^ 0)));
}

/// 2.74
int two_tsub_ok(int x, int y) {
    int w = (sizeof(int) << 3) - 1;
    int mark1 = ~(x ^ -y) >> w;
    int mark2 = ((x - y) ^ -y) >> w;
    int mark = !(mark1 && mark2);
    return mark;
}

/// 2.75
//unsigned two_unsigned_high_prod(unsigned x, unsigned y) {
//    int sx = x;
//    int sy = y;
//    int xw = sx >> ((sizeof(int) << 2^3) - 1);
//    int yw = sy >> ((sizeof(int) << 2^3) - 1);
//    unsigned high_prod = signed_high_prod(sx, sy) + sx & yw + sy & xw;
//    return high_prod;
//}

/// 2.76
void *two_calloc(size_t nmemb, size_t size) {
    size_t s = nmemb * size;
    
    if (s == 0) {
        return NULL;
    }
    
    if (s / nmemb == size) {
        void *aa = malloc(s);
        aa = memset(aa, 0, s);
        return aa;
    }
    return NULL;
}

/// 2.77
void two_multiply(int x) {
    // A
    int resultA = (x << 4) + x;
    
    // B
    int resultB = -(x << 3) + x;
    
    // C
    int resultC = (x << 6) - (x << 2);
    
    // D
    int reslutD = -(x << 7) + (x << 4);
    
    printf("%d %d %d %d", resultA, resultB, resultC, reslutD);
}

/// 2.78
int two_divide_powers(int x, int k) {
    int offset = (0x01 << 31) & x && 1;
    return (x + (offset << k) - offset) >> k;
}

/// 2.79
int two_mul3div4(int x) {
    x = (x << 1) + x;
    return two_divide_powers(x, 2);
}

/// 2.80
void two_threeFourths(int x) {
    int f = x & ~0x3;
    int l = x & 0x3;
    f = ((f >> 2) << 1) + f;
    int is_neg = (0x01 << 31) & x && 1;
    l = (l << 1) + l;
    l = (l + (is_neg << 2) - is_neg) >> 2;
    printf("%d", l + f);
}

/// 2.81
void two_createBit(int j, int k) {
    // A
    int a = -1 << k;
    // B
    int b = (-1 << (j + k)) ^ -1;
    b = b >> j << j;
    printf("%x %x \n", a, b);
}

/// 2.82
void two_judeTrueOrFalse() {
    // A: 1     正确答案为 0
    // B: 1 ----
    // C: 0     正确答案为 1
    // D: 1 ----
    // E: 0     正确答案为 1
}

/// 2.83  没有自己做出来
void two_eightTreeProblem() {
    // A: Y / (2^k -1)
}

/// 2.84  没有自己做出来
int two_float_le(float x, float y) {
    /*
     
     */
    return 1;
}

/// 2.85
void two_float_express() {
    /*
     A: E = 2, f = 2^-1 + 2^-2, M = 1 + f, V = 2^2 * M
     B: E = 2^(k-1) - 1, f = 1 - (n - 2^(k-1) + 1) / 2^n, M = 1 + f, V = 2^E * M
     C: E = 2^(k-1) -2 + n, f = 0, M = 1, V = 2^(2^(k-1) -2 + n)
     */
}

/// 2.86
void two_newFloat() {
    /*
      1/2^16445
     (1+2^63)/2^16445
     (1-2^-64) * 2^16384
     */
}

/// 2.89
void two_eightNine() {
    /*
     A: YES
     B: NO
     C: YES
     D: YES
     E: YES
     */
}

/// 2.90
float two_fpwr2(int x) {
    unsigned exp, frac;
    unsigned u;
    
    if (x < -23) {
        exp = 0x00000000;
        frac = 0x00000000;
    } else if (x < 0) {
        exp = 0x00000000;
        frac = 2^x;
    } else if (x < 128) {
        exp = 2^x + 127;
        frac = 0;
    } else {
        exp = 0x11;
        frac = 0;
    }
    u = exp << 23 | frac;
    return (float)u;
}

/// 2.91
void two_nineZero() {
    /*
     0 10000000 10010010000111111011011
     A: 11.0010010000111111011011
     B: 11.001001001001001001001...
     C: 9
     */
}

void callTwoFunction(void) {
    unsigned a = -1;
    a = a >> 1;
    printf("%d \n", (int)a);
    printf("%x \n", two_tsub_ok(-2222222, 1));
}
