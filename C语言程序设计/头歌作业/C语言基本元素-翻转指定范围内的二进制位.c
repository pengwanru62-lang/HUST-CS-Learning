#include <stdio.h>

int main(){
	int x,n,p,mask;
	scanf("%d %d %d", &x,&p, &n);
	
	mask=((1<<n)-1);
	x=x ^ (mask<<p-n+1);//计算机为第012345位 
	
	printf("%d",x);
	return 0;
	
}/*先1<<n使第n位为1，-1后让第0到n-1位为1，一共n个1；
将末尾的1与第p-(n-1)位对齐 
之后再异或操作实现翻转*/ 
