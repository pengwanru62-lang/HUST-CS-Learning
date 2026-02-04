#include <stdio.h>
#include <string.h>
int main() {
	char ac[200];
	char bc[200];
	gets(ac);
	gets(bc);

	int num1=strlen(ac);
	int num2=strlen(bc);

	if(ac[0]=='0'||bc[0]=='0') {
		printf("0");
		return 0;
	}

	int a[200];
	int b[200];

	int i;
	for(i=0; i<num1; i++) {
		a[i]=ac[num1-1-i]-'0';
	}
	for(i=0; i<num2; i++) {
		b[i]=bc[num2-1-i]-'0';
	}

	int s=0,t=0;
	int result[450]= {0};

	int j;
	for(i=0; i<num1; i++) {
		for(j=0; j<num2; j++) {
			result[s]=result[s]+a[i]*b[j];
			result[s+1]=result[s+1]+result[s]/10;
			result[s]=result[s]%10;
			s++;
		}
		t++;
		s=t;
	}
	s=num1+num2;
	while(result[s]==0) {
		s--;
	}
	for(i=s; i>=0; i--) {
		printf("%d",result[i]);
	}
	return 0;
}

