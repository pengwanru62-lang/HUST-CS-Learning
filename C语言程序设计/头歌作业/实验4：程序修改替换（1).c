#include<stdio.h>
long long sum_fac(int n); 
int main(void)
{
	int k;
	for(k=1; k<=20; k++)
		printf("k=%d the sum is %lld\n",k,sum_fac(k));
	return 0;
}
long long sum_fac(int n)
{
	if(n==1)return 1;
	long long fac_n=1;
	int i;
	for(i=1;i<=n;i++){
		fac_n*=i;
	}
	return fac_n+sum_fac(n-1);
}
