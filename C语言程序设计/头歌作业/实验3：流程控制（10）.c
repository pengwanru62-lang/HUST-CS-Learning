#include <stdio.h>
#include <math.h>
int isprime(long long n){
	if(n==1||n==0)return 0;
	if(n==2)return 1;
	if(n%2==0) return 0;
	
	long long i;
	for(i=3;i<=sqrt(n);i+=2){
		if(n%i==0) return 0;
	}
	return 1;
}

int main(){
	long long m;
	scanf("%lld",&m);
	if(m<=3) printf("wrong input!");
	int i;
	
	for(i=2;(pow(2,i)-1)<=m;i++){
		if(isprime(i)){
			long long k=pow(2,i)-1;
			if(isprime(k)){
				printf("M(%d)=%lld\n",i,k);
			}
		}
	}
	return 0;
}
