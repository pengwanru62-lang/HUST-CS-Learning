#include <stdio.h>
int zuheshu(int n,int k){
	if(k==0) return 1;
	
	int ans =1;
	if(k>n-k) k=n-k;
	
	int i;
	for(i=0;i<k;i++){
		ans=ans*(n-i)/(i+1);
	}
	return ans;
}

int main(){
	int n;
	scanf("%d",&n);
	
	int i=0;
	for(i=0;i<=n;i++){
		
		int k=0;
		for(k;k<n-i;k++){
			printf("  ");
		}
		
		int j;
		for(j=0;j<=i;j++){
			printf("%-4d",zuheshu(i,j));
		}
		printf("\n");
	}
	return 0;
}
