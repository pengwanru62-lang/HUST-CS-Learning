#include<stdio.h>
int main()
{
	int i,x,k,flag=0;
//	printf("本程序判断合数，请输入大于1的整数，以Ctrl+Z结束\n");
	while(scanf("%d",&x)!=EOF){
		flag=0;//执行完上一次循环后flag重置 
		for(i=2,k=x>>1; i<=k; i++)//k向右边移动一位相当于除以2 
			if(!(x%i)){//符号优先级错误 !x%i
				flag=1;
				break;
			}
		if(flag==1) printf("%d是合数",x);//修正比较运算符flag=1 
		else printf("%d不是合数",x); 
	}
	return 0;
}
