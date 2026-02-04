#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	unsigned char *p=(unsigned char*)&n;
	int i;
	for(i=3;i>=0;i--){	
	unsigned char m=*(p+i);
	unsigned h=(m>>4)&0x0f;
	unsigned l=(m)&0x0f;
	printf("%x %x ",h,l);
	}
	return 0;
}
