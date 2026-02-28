#include <stdio.h>
int main(){
	int x,n;
	scanf("%d %d",&n,&x);
	int cnt=0;
	int i; 
	for(i=1;i<=n;i++){
		if(i==x){
			cnt++;
		}else{
			int j=i;
			for(;j>0;j/=10){
				int temp=j%10;
				if(temp==x){
					cnt++;
				}
			}
		}
	}
		printf("%d",cnt);
		return 0;
} 
