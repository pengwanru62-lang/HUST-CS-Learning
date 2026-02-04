#include<stdio.h>
int main()
{
	int i,x,k,flag=0;
//	printf("本程序判断合数，请输入大于1的整数，以Ctrl+Z结束\n");
scanf("%d",&x);
while(x==EOF) return 0;
	do{
        flag=0;
		for(i=2,k=x>>1;flag==0&&i<=k; i++)
			if(!(x%i)){
				flag=1;
				//break;
			}
		if(flag==1) printf("%d是合数",x);
		else printf("%d不是合数",x); 
	}while(scanf("%d",&x)!=EOF);
	return 0;
}
