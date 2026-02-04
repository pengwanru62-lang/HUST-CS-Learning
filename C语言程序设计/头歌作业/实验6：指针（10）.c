#include <stdio.h>
#include <string.h>
int strSub(char *a,char *b);
int main() {
	char a[100],b[100];

	fgets(a,sizeof(a),stdin);
	a[strcspn(a,"\n")]='\0';
	fgets(b,sizeof(b),stdin);
	b[strcspn(b,"\n")]='\0';

	int k=strSub(a,b);

	printf("%s\n",a);
	printf("%d",k);
	return 0;
}

int strSub(char *a,char *b) {
	char *pauze=strstr(a,b);
	char *temp;
	if(pauze==NULL)return 0;

	int n=strlen(b);
	while(pauze!=NULL) {
		temp=pauze;

		while(*(pauze+n)) {
			*pauze=*(pauze+n);
			pauze++;
		}
		*pauze = '\0'; //在一次删除完成之后需要补充字符末尾的结束符
		pauze=strstr(temp,b);

	}
	return 1;
}
