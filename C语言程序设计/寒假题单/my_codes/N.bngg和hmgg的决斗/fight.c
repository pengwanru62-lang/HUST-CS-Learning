#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
int main(){
	long long n,m,p1,s1,s2;
	scanf("%lld",&n);
	long long *c=(long long *)malloc((n+1)*sizeof(long long));
	
	int i;
	for(i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	c[0]=0;
	
	scanf("%lld",&m);
	scanf("%lld",&p1);
	scanf("%lld",&s1);
	scanf("%lld",&s2);
	
	long long bngg;
	long long hmgg;
	if(p1<m){
		bngg=s1*llabs(p1-m);
		hmgg=0;
	}else if(p1>m){
		bngg=0;
		hmgg=s1*llabs(m-p1);
	}
	for(i=1;i<m;i++){
		bngg+=c[i]*(m-i);
	}
	for(i=n;i>m;i--){
		hmgg+=c[i]*(i-m);
	}
	int flag=0;
	long long min=-1;
	long long p2=1;
	long long temp;
	long long best_p2;
	for(p2=1;p2<=n;p2++){
		long long new_bngg=bngg;
		long long new_hmgg=hmgg;
		
		if(p2<m){
			new_bngg+=s2*(m-p2);
		}else if(p2>m){
			new_hmgg+=s2*(m-p2);
		}
		
		temp=llabs(new_hmgg-new_bngg);
		if(min==-1||temp<min){
			min=temp;
			best_p2=p2;
		}
	}
	printf("%lld",best_p2);
	free(c);
	return 0;
} 
