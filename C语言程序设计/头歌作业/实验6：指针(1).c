#include <stdio.h>
char * strcopy(char *,const char *);
int main() {
	char *s1,*s2,*s3;
	char a[100],b[100],c[100];
	s1=a,s2=b,s3=c;

	scanf("%s",s2);
	strcopy(s1,s2);
	printf("%s\n",s1);
	scanf("%s\n",s2);
	s3=strcopy(s1,s2);
	printf("%s\n",s3);
	return 0;
}
char * strcopy(char *t,const char *s) {
	char *p=t;
	while(*t++=*s++);
	*t='\0';
	return(p);
}
