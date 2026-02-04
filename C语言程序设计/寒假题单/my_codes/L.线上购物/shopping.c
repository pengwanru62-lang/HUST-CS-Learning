#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	int *goods=(int *)malloc(n*sizeof(int));
	if(goods==NULL) return 1;
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&goods[i]);
	}
	int *nums=(int *)malloc(q*sizeof(int));
	memset(nums,-1,q*sizeof(int));
	for(i=0;i<q;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		int min,flag=0;
		int j;
		for(j=0;j<n;j++){
			if(goods[j]%(int)(pow(10,a))==b){
				if(!flag) min=goods[j];
				flag=1;
				if(goods[j]<min){
					min=goods[j];
				}
			}
		}
		if(!flag)continue;
		nums[i]=min;
	}
	for(i=0;i<q;i++){
		printf("%d\n",nums[i]);
	}
	free(goods);
	free(nums);
	return 0;
} 
