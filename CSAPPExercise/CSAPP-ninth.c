//
//  CSAPP-ninth.c
//  CSAPPExercise
//
//  Created by 彭作青 on 2020/6/29.
//  Copyright © 2020 彭作青. All rights reserved.
//

#include "CSAPP-ninth.h"
#include "csapp.h"

// 9.11
/*
 0x027c
 A: 00001001 111100
 B: VPN 0x09
    TLBI 01
    TLBT 02
    TLB命中  否
    缺页  否
    PPN 17
 C: 物理地址
    010111 1111 00
 D: 0
    0xf
    0x17
    NO
    -
 **/

// 9.12
/*
 0x03a9
 A: 000011 10 101001
 B: VPN 0x0e
    TLBI 0x2
    TLBT 0x03
    TLB命中  否
    缺页  否
    PPN 0x11
 C: 物理地址
    010001 1010 01
 D: 0x1
    0xa
    0x11
    NO
    -
 **/

// 9.13
/*
 0x0040
 A: 00000001 000000
 B: VPN 0x01
    TLBI 0x1
    TLBT 0x00
    TLB命中  否
    缺页  是
    PPN --
 **/

// 9.14

void ninth_changeHelloToJello() {
    int fp = open("openFile.txt", O_RDWR, 0);
    struct stat testStat;
    
    fstat(fp, &testStat);
    int *buf = mmap(NULL, testStat.st_size, PROT_WRITE, MAP_PRIVATE, fp, 0);
    char *first = (char *)buf;
    first[0] = 'd';
    printf("%s\n", (char *)buf);
    size_t result = write(fp, buf,1);
    printf("%ld \n", result);
}

// 9.15
/*
 8  0x9
 16 0x11
 24 0x19
 32 0x21
 **/


