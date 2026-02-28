#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
	return (*(int *)a-*(int *)b);
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	
	int *a=(int *)malloc(n*sizeof(int));
	if(a==NULL)return 0;
	
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	qsort(a,n,sizeof(int),cmp);
	
	int cnt=0;
	for(i=0;i<n;i++){
		if(i==0||a[i]!=a[i-1]){
			cnt++;
			if(cnt==k){
				printf("%d",a[i]);
				free(a);
				return 0;
			}
		}
	}
	printf("NO RESULT");
	free(a);
	return 0;
}
