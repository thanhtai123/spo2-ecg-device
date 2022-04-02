#ifndef _HR_H_
#define _HR_H_

#include "stm32f10x.h"
#include <math.h>

#define	NUM_OF_SAMPLE	1024
#define LOG2N_OF_NUM	10
#define	SAMPLE_RATE		100
#define PI	(3.14159265359)

//complex data structure
struct complex {
	double r,i;
};
typedef	struct complex complex;
complex setComplex(double r, double i);
complex mulComplex(complex a, complex b);

//fourier function
int revBit(u16 nbit, u16 mask);
//user set data
void setData(int32_t data, u16 index);
complex* checkValid(void);
//
uint32_t getHR(void);

#endif