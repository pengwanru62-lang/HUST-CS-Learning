#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	
	int num[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	
	int count=0;
	for(i=1;i<n;i++){
		if((num[i]>num[i-1])&&(num[i]>num[i+1])||(num[i]<num[i-1]&&num[i]<num[i+1]))
		count++;
	}
	printf("%d",count);
	return 0;
}
