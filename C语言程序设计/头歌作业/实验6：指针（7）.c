#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void RemoveSame(int *a,int n) {
	int *b=(int*)malloc(n*sizeof(int));
	if(b==NULL)return;
	int i;
	int *temp=b;
	for(i=0; i<n; i++) {
		*(temp+i)=0;
	}

	int j;
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if((*(a+i))==(*(a+j))) {
				*(b+i)=1;
			}
		}
	}

	int cnt=0;
	for(i=0; i<n; i++) {
		if(*(b+i)==0) {
			cnt++;
			if(cnt==1) printf("%d",*(a+i));
			else printf(" %d",*(a+i));
		}
	}
	printf("\n%d",cnt);
	free(b);
	return;
}

int main() {
	int n;
	scanf("%d",&n);

	int *a=(int*)malloc(n*sizeof(int));
	if(a==NULL) return 1;

	int i;
	for(i=0; i<n; i++) {
		scanf("%d",a+i);
	}

	RemoveSame(a,n);

	free(a);
	return 0;
}
