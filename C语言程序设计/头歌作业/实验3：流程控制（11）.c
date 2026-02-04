#include <stdio.h>
int main(){
	int m;
	scanf("%ld",&m);
	
	int isprime[1000001];

    //初始标记	
	long i;
	for(i=0;i<=m;i++){
		isprime[i]=1;
	}
	isprime[0]=0;
	isprime[1]=0;
	
	// 筛选
	long k;
	for(k=2;k<=m;k++){
		if(isprime[k]){
			long j;
			for(j=k*k;j<=m;j+=k)isprime[j]=0;
		}
	} 


	//输出孪生素数
	long n;
	for(n=2;n<=m-2;n++){
		if(isprime[n]&&isprime[n+2]){
			printf("(%ld,%ld) ",n,n+2);
		}
	} 
	return 0;
}
//对于这一类比较大的数字，建议使用long避免溢出的风险 
