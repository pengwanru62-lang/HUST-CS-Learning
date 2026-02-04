# include <stdio.h>
int main() {
	int x;
	scanf("%d",&x);
	char str[40];
	str[4]=str[9]=str[14]=str[19]=str[24]=str[29]=str[34]=' ';

	int i;
	for(i=38; i>=35; i--) {
		str[i]=(x&1)+'0';
		x>>=1;
	}

	for(i=33; i>=30; i--) {
		str[i]=(x&1)+'0';
		x>>=1;
	}
	for(i=28; i>=25; i--) {
		str[i]=(x&1)+'0';
		x>>=1;
	}
	for(i=23; i>=20; i--) {
		str[i]=(x&1)+'0';
		x>>=1;
	}
	for(i=18; i>=15; i--) {
		str[i]=(x&1)+'0';
		x>>=1;
	}
	for(i=13; i>=10; i--) {
		str[i]=(x&1)+'0';
		x>>=1;
	}
	for(i=8; i>=5; i--) {
		str[i]=(x&1)+'0';
		x>>=1;
	}
	for(i=3; i>=0; i--) {
		str[i]=(x&1)+'0';
		x>>=1;
	}
	str[39]='\0';
	printf("%s",str);
	return 0;
}
