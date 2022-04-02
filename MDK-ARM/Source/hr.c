#include "hr.h"

complex dataToProcess1[NUM_OF_SAMPLE];

//fourier transform algorithm
complex setComplex(double r, double i){
	complex rs;
	rs.r = r;
	rs.i = i;
	return rs;
}
complex mulComplex(complex a, complex b){
	complex rs;
	rs.r = a.r * b.r - a.i * b.i;
	rs.i = a.i * b.r + a.r * b.i;
	return rs;
}
int revBit(u16 nbit, u16 mask){
	int i, j;
	for (i = 0, j = nbit - 1; i <= j; ++i, --j)
	{
		if ((mask >> i & 1) != (mask >> j & 1))
		{
			mask ^= 1 << i;
			mask ^= 1 << j;
		}
	}
	return mask;
}
complex* fft(u16 n, complex* arr, u16 np, u8 inv) {
	u16 i, j, k;
	for (i = 0; i < n; ++i)
	{
		j = revBit(np, i);
		if (i < j) {
			complex temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	for (u16 s = 1;s <= np;s++) {
		int m = 1 << s;
		const complex wn = inv ? setComplex(cos(-2 * PI / m), sin(-2 * PI / m)) : setComplex(cos(2 * PI / m), sin(2 * PI / m));
		for (k = 0;k < n;k += m) {
			complex w = setComplex(1, 0);
			for (j = 0;j < m / 2;j++) {
				complex t = mulComplex(w, arr[k + j + m / 2]);
				complex u = arr[k + j];
				arr[k + j].r = t.r + u.r;
				arr[k + j].i = t.i + u.i;
				arr[k + j + m / 2].r = -t.r + u.r;
				arr[k + j + m / 2].i = -t.i + u.i;
				w = mulComplex(w, wn);
			}
		}
	}
	if (inv) {
		for (j = 0;j < n - 1; j++) {
			arr[j].r /= n;
			arr[j].i /= n;
		};
	}
	return arr;
}

void setData(int32_t data, u16 index){
	dataToProcess1[index].r = data;
	dataToProcess1[index].i = 0;
}

uint32_t getHR(void){
	complex *fftData = fft(NUM_OF_SAMPLE,dataToProcess1,LOG2N_OF_NUM,0);
	u16 i;
	uint16_t bound = 3*NUM_OF_SAMPLE/SAMPLE_RATE;
	uint16_t maxValue = 0,maxIndex=0;
	for(i=1;i<bound;i++){
		int16_t tempR = fftData[i].r;
		int16_t tempI = fftData[i].i;
		uint16_t tempS = sqrt(tempR*tempR+tempI*tempI);
		if(tempS>maxValue) {
			maxValue=tempS;
			maxIndex=i;
		}
	}
	return SAMPLE_RATE*maxIndex*60/NUM_OF_SAMPLE;
	//return maxIndex;
}

complex* checkValid(void){

	return dataToProcess1;
	//return fft(NUM_OF_SAMPLE,dataToProcess1,LOG2N_OF_NUM,0);
}

