/***定义两个带参数的宏,用于计算三角形面积***/
#include<stdio.h>
#include<math.h>
#define area(s,a,b,c) (s*(s-a)*(s-b)*(s-c))
#define s(a,b,c) ((a+b+c)/2.0)//注意除以2.0发 
int main(void)
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	float area,s;
	s=s(a,b,c);
	area=area(s,a,b,c);
	printf("%.2f",sqrt((double)(area)));
	return 0;
}
