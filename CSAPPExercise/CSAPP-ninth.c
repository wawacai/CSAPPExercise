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

// 9.16
/*
 16 16 16
 8  16 16
 16 16  16
 8  16  16
 **/

// 9.17

/* Basic constants and macros */
#define WSIZE       4       /* Word and header/footer size (bytes) */ //line:vm:mm:beginconst
#define DSIZE       8       /* Double word size (bytes) */
#define CHUNKSIZE  (1<<12)  /* Extend heap by this amount (bytes) */  //line:vm:mm:endconst

#define NINE_MAX(x,y) ((x) > (y)?(x) : (y))

#define PACK(size, alloc)  ((size) | (alloc)) //line:vm:mm:pack
 
/* Read and write a word at address p */
#define GET(p)       (*(unsigned int *)(p))            //line:vm:mm:get
#define PUT(p, val)  (*(unsigned int *)(p) = (val))    //line:vm:mm:put
 
/* Read the size and allocated fields from address p */
#define GET_SIZE(p)  (GET(p) & ~0x7)                   //line:vm:mm:getsize
#define GET_ALLOC(p) (GET(p) & 0x1)                    //line:vm:mm:getalloc
#define GET_PREVIOUS_ALLOC(p) (GET(p) & 0x2) /* ! CHANGED ! */
 
/* Given block ptr bp, compute address of its header and footer */
#define HDRP(bp)       ((char *)(bp) - WSIZE)                      //line:vm:mm:hdrp
#define FTRP(bp)       ((char *)(bp) + GET_SIZE(HDRP(bp)) - DSIZE) //line:vm:mm:ftrp
 
/* Given block ptr bp, compute address of next and previous blocks */
#define NEXT_BLKP(bp)  ((char *)(bp) + GET_SIZE(((char *)(bp) - WSIZE))) //line:vm:mm:nextblkp
#define PREV_BLKP(bp)  ((char *)(bp) - GET_SIZE(((char *)(bp) - DSIZE)))


/* Global variables */
static char *mem_max_addr;
static char *heap_listp = 0;  /* Pointer to first block */
static char *rover;           /* Next fit rover */

void *nine_nextFit(int asize) {
    char *oldRover = rover;
    
    for (; rover < mem_max_addr; NEXT_BLKP(rover)) {
        if (!GET_ALLOC(HDRP(rover)) && GET_SIZE(HDRP(rover)) >= asize) {
            return rover;
        }
    }
    
    for (rover = heap_listp; rover < oldRover; NEXT_BLKP(rover)) {
        if (!GET_ALLOC(HDRP(rover)) && GET_SIZE(HDRP(rover)) >= asize) {
            return rover;
        }
    }
    
    return NULL;
}

// 9.18
// https://dreamanddead.gitbooks.io/csapp-3e-solutions/chapter9/9.18.html

// 9.19
// a d b
