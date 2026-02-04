#include<stdio.h>
double mulx(double x,int n);
long long fac(int n);

double sum(double x,int n)
{
	int i;
	double z=1.0;
	for(i=1;i<=n;i++){
		z=z+ mulx(x,i)/fac(i);//原始代码效率较低的原因在这一行，每次都要计算分子分母 
	}
	/*for (int i = 1; i <= n; i++) {
        pow_x = pow_x * x;   // x^i
        fac = fac * i;       // i!
        result += pow_x / fac;
    }*/
	return z;
}

double mulx(double x,int n)
{
	static int i=0;
	static double z=1.0;
	//如果需要更小的n，则重置
	if(n<i){
		i=0;
		z=1.0;
	} 
	while(i<n){
		z*=x;
		i++;
	}
	return z;
}

long long fac(int n)
{
	static int i=1;
	static long long h=1;
	if(n<i){
		h=1;
		i=1;
	}
	while(i<=n){
		h*=i;
		i++;
	}
	return h;
}

int main()
{
	double x;
	int n;
	scanf("%lf%d",&x,&n);
	printf("The result is %lf",sum(x,n));
	return 0;
} 
