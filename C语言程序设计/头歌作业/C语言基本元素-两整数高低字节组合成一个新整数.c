#include <stdio.h>

int main(){
	short k,p;
	scanf("%hd %hd", &k, &p);
	//当 k 是负数时（如 -32768），k >> 8 进行的是算术右移，会进行符号扩展 
	k = (k>>8) & 0x00FF;
	p = p & 0x00FF;
	
	short result = k | (p<<8);
	printf("%hd", result);
	return 0; 
} 
