#include <stdio.h>
int main() {
	int A,B,C;
	scanf("%d %d %d",&A,&B,&C);
	if((B>=A&&A>=C)||(C>=A&&A>=B)) {
		printf("A %d",A);
	} else if((C>=B&&B>=A)||(A>=B&&B>=C)) {
		if(B==A) {
			printf("A %d",A);
		} else {
			printf("B %d",B);
		}
	} else if((A>=C&&C>=B)||(B>=C&&C>=A)) {
		if (A==C) {
			printf("A %d",A);
		} else if(A!=C&&B==C) {
			printf("B %d",B);
		} else {
			printf("C %d",C);
		}

	}
	return 0;
}
