#include <stdio.h>
int main() {
	long double e;
	scanf("%Lf",&e);

	long double pie=1.0,pro=1.0;

	int i;
	for(i=1; pro>=e; i++) {
		pro=1.0/(2*i+1);

		if(i%2==0) {
			pie+=pro;
		} else if(i%2!=0) {
			pie-=pro;
		}
	}
	printf("%.6Lf",pie*4);
	return 0;
}
