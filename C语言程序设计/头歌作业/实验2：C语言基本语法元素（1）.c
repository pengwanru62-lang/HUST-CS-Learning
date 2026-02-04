 #include<stdio.h>
#define PI 3.14159
int main(){
	int f;
	short p, k;
	double c, r, s;
	
	/*任务1*/
	printf("Input Fahrenheit:");
	scanf("%d", &f);
	c=(5.0/9.0)*((double)f-32.0);
	printf("\n %d(F)=%.2f(C)\n\n",f,c);
	/*任务2*/
	printf("input the radius r:");
	scanf("%lf",&r);
	s = PI * r * r;
	printf("\nThe acreage is %.2f\n\n", s);
	/*任务3*/
	k=0xa1b2, p=0x8423;
	short newint = (p&0xff00) | ((k>>8)&0x00ff);
	printf("new int = %#x\n\n",(unsigned short)newint);//使用unsigned防止short被提升为int的时候符号位扩展全部变成1而不是目标的0 
	return 0;  
}
