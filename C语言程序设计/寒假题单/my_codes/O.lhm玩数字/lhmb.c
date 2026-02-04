#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int *nums=(int *)malloc(sizeof(int)*n);
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d",&nums[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(nums[j]>nums[j+1]){
				int temp=nums[j];
				nums[j]=nums[j+1];
				nums[j+1]=temp;
			}
		}
	}
	int flag=0;
	for(i=0;i<n;i++){
		int temp=nums[i];
		while(nums[i]==nums[i+1])i++;
		flag++;
		if(flag==k)break;
	}
	if(flag==k){
		printf("%d",nums[i]);
	}else{
		printf("NO RESULT"); 
	}
	free(nums);
	return 0;
}
