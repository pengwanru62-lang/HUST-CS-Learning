#include <stdio.h>
#include <math.h>
int main(){
	int n;
	scanf("%d",&n);
	int max=pow(10,n);
	int min=pow(10,n-1); 
	int i;
	for(i=min;i<max;i++){
		int pingfang=i*i;
		int m=pingfang%max;//pow() 函数返回的是 double 类型, % 运算符要求整数操作数
		if(m==i)printf("%d ",i);
	}
	return 0;
}
