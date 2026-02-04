#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d",&n);

	int **m=(int**)malloc(n*sizeof(int*));
	int i;
	for(i=0; i<n; i++) {
		m[i]=(int*)malloc(n*sizeof(int));
	}

	int top=0,bottom=n-1;
	int l=0,r=n-1;
	int cnt=1;

	while(l<=r&&top<=bottom) {
		for(i=l; i<=r; i++) {
			m[top][i]=cnt++;
		}
		top++;

		for(i=top; i<=bottom; i++) {
			m[i][r]=cnt++;
		}
		r--;

		if(top<bottom) {
			for(i=r; i>=l; i--) {
				m[bottom][i]=cnt++;
			}
			bottom--;
		}

		if(l<r) {
			for(i=bottom; i>=top; i--) {
				m[i][l]=cnt++;
			}
			l++;
		}
	}

	for(i=0; i<n; i++) {
		int j;
		for(j=0; j<n; j++) {
			printf("%d",m[i][j]);
			if(j<=n-2)printf(" ");
		}
		printf("\n");
	}

	for(i=0; i<n; i++) {
		free(m[i]);
	}
	free(m);
	return 0;
}
