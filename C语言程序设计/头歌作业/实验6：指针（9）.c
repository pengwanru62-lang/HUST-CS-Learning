#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sort(int *a,int len,int order) {
	int i,j;
	for(i=0; i<len; i++) {
		for(j=0; j<len-i-1; j++) {
			if(a[j]>a[j+1]) {
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	if(order==1) {
		for(i=0,j=len-1; i<j; i++,j--) {
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
}

int main(int argc,char *argv[]) {
	int N=atoi(argv[1]);
	int*a=(int *)malloc(N*sizeof(int));
	int i;
	for(i=0; i<N; i++) {
		scanf("%d",a+i);
	}
	if(argc==3) {
		sort(a,N,1);
	} else {
		sort(a,N,0);
	}

	for(i=0; i<N; i++) {
		printf("%d",*(a+i));
		if(i<N-1)printf(" ");
	}
	free(a);
	return 0;
}
