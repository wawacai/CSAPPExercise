//
//  CSAPP-five.c
//  CSAPPExercise
//
//  Created by 彭作青 on 2020/4/2.
//  Copyright © 2020 彭作青. All rights reserved.
//

#include "CSAPP-five.h"

// 5.13
/*
 B:浮点数加法的延迟
 C:整数加法的延迟
 D:关键路径是加法，加法依赖于上一次的结果，浮点数加法延迟为3个周期，所以CPE为3.00
 */

typedef long data_t;

typedef struct {
    long len;
    data_t *data;
} vec_rec, *vec_ptr;

// 5.14
void inner4(vec_ptr u, vec_ptr v, data_t *dest) {
    long i;
    long length = u->len;
    data_t *udata = u->data;
    data_t *vdata = v->data;
    data_t sum = (data_t)0;
    
    for (i = 0; i < length-5; i+=5) {
        sum = sum + udata[i] * vdata[i] + udata[i+1] * vdata[i+1] + udata[i+2] * vdata[i+2] + udata[i+3] * vdata[i+3] + udata[i+4] * vdata[i+4] + udata[i+5] * vdata[i+5];
    }
    
    for (; i < length; i++) {
        sum  = sum + udata[i] * vdata[i];
    }
    *dest = sum;
}

/*
 A:本题的代码有n（数据规模）次加运算和乘运算。cpe最低的情况是加的功能功能单元和乘的功能单元全都处于满流水的状态，此时加和乘都达到吞吐量下界。对于整数运算，加法的吞吐量下界为0.5，乘法的吞吐量下界为1.0，所以cpe=max{0.5,1.0}；对于浮点数运算，加法的吞吐量下界是1.0，乘法的吞吐量下界是0.5，所以cpe=max{1.0,0.5}=1.0。综上，cpe的下界是1.0。
 B:只减少了循环的次数（所以整数的CPE下降了，书上把这个称为“overhead”），并没有减少内存读写的次数和流水线的发生，所以浮点数运算还是不能突破“关键路径”的CPE下界。
 */
