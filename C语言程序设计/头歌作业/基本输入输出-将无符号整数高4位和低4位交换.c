#include <stdio.h>

int main(){
	unsigned short k;
	scanf("%hu", &k);//k进行的是值运算，而不是直接修改变量本身
	/*0x000F:0000 0000 0000 1111取低四位 
	0xFF:1111 1111取低八位 
	0xF0:1111 0000取高四位 
	0x0F:0000 1111取低四位*/
	
	unsigned short low4 = (k<<12) & 0xF000;
	unsigned short high4 = (k>>12) & 0x000F;
	unsigned short mid8 = k & 0x0FF0;
	
	k = low4 | high4 | mid8;
	
	printf("%hu", k);
	return 0;
	
}

