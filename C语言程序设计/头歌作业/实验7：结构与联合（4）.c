#include <stdio.h>

struct bits {
	unsigned int bit0:1;
	unsigned int bit1:1;
	unsigned int bit2:1;
	unsigned int bit3:1;
	unsigned int bit4:1;
	unsigned int bit5:1;
	unsigned int bit6:1;
	unsigned int bit7:1;
} b;

void f0(int b) {
	printf("the function %d is called!\n",b);
}
void f1(int b) {
	printf("the function %d is called!\n",b);
}
void f2(int b) {
	printf("the function %d is called!\n",b);
}
void f3(int b) {
	printf("the function %d is called!\n",b);
}
void f4(int b) {
	printf("the function %d is called!\n",b);
}
void f5(int b) {
	printf("the function %d is called!\n",b);
}
void f6(int b) {
	printf("the function %d is called!\n",b);
}
void f7(int b) {
	printf("the function %d is called!\n",b);
}

int main() {
	unsigned char x;
	scanf("%hhu",&x);

	b.bit0=x&0x01;
	b.bit1=(x>>1)&0x01;
	b.bit2=(x>>2)&0x01;
	b.bit3=(x>>3)&0x01;
	b.bit4=(x>>4)&0x01;
	b.bit5=(x>>5)&0x01;
	b.bit6=(x>>6)&0x01;
	b.bit7=(x>>7)&0x01;

	void (*p_fun[8]) (int)= {f0,f1,f2,f3,f4,f5,f6,f7};

	if(b.bit0) p_fun[0](0);
	if(b.bit1) p_fun[1](1);
	if(b.bit2) p_fun[2](2);
	if(b.bit3) p_fun[3](3);
	if(b.bit4) p_fun[4](4);
	if(b.bit5) p_fun[5](5);
	if(b.bit6) p_fun[6](6);
	if(b.bit7) p_fun[7](7);

	return 0;
}

