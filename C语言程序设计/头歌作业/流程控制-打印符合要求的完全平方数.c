#include <stdio.h>
#include <math.h>
int main () {
	int n;
	scanf("%d",&n);

	int i;
	for (i=0; i<=n; i++) {
		int m=sqrt(i);
		if (m*m==i) {
			int c=(m*m)%10;
			int b2=(m*m)/10;
			int left=m*m;
			

			if(b2>0) {
				int k;
				for(k=1; k<m; k++) {
					int left0=i-k*k*10;//先减了再判断left0是不是完全平方数 
					int left1=sqrt(left0);
					if(left1*left1==left0) {
						printf("%d=%d*%d=%d*%d*10+%d*%d\n",i,m,m,k,k,left1,left1);
						break;
					}
				}
			}

		}
	}
	return 0;
}
