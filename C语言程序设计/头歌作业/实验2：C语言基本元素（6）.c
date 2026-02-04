#include <stdio.h>
int main() {
	unsigned long n;
	unsigned long ch[4];

	while (scanf("%lu",&n)!=EOF) {
		ch[0]=n>> 24;
		ch[1]=n<<8>>24;
		ch[2]=n<<16>>24;
		ch[3]=n<<24>>24;
		printf("%lu.%lu.%lu.%lu",ch[0],ch[1],ch[2],ch[3]);
	}
	return 0;
}
