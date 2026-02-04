#include <stdio.h>
#include <stdlib.h> 
int main(){
	int N;
	scanf("%d",&N);
	int *nums=(int *)malloc(N*N*sizeof(int));
	int i=0;
	int x;
	while(scanf("%d",&x)==1){
		nums[i++]=x;
		char c=getchar();
		if(c=='\n')break;
		ungetc(c,stdin);
	}
	int lines=0;
	int j;
	for(j=0;j<i;j++){
		if(j%2==0){
			int k;
			for(k=0;k<nums[j];k++){
				if(lines>0&&lines%N==0) printf("\n");
				printf("0");
				lines++;
			}
		}else{
			int k;
			for(k=0;k<nums[j];k++){
				if(lines>0&&lines%N==0) printf("\n");
				printf("1");
				lines++;
		}
	}
}
	free(nums);
	return 0;
}


