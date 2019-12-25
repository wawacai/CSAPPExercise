//
//  CSAPP-two.c
//  CExerciseDemoSet
//
//  Created by 彭作青 on 2019/12/13.
//  Copyright © 2019 彭作青. All rights reserved.
//

#include "CSAPP-two.h"

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

void callTwoFunction(void) {
    printf("%d \n", two_fits_bits(-4, 3));
    
//    printf("%d \n", two_int_shifts_are_arithmetic());
//    two_replace_byte(0x12345678, 0, 0xAB);
//    two_combination(0x89ABCDEF, 0X76543210);
//    printf("%d \n", two_judgeInt(0x2345688));
}
