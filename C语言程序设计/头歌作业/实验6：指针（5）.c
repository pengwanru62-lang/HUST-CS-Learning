#include <stdio.h>
#include <string.h>
int main() {
	char*(*p[3])(char a[80],char b[80])= {strcpy,strcat,strtok};
	char a[80],b[80],*result;
	int choice;
	while(1) {
		do {
			scanf("%d",&choice);
		} while(choice<1||choice>4);
		getchar();
		if(choice==4) {
			goto down;
		} else {
			fgets(a,sizeof(a),stdin);
			a[strcspn(a,"\n")]='\0';
			fgets(b,sizeof(b),stdin);
			b[strcspn(b,"\n")]='\0';
			result=p[choice-1](a,b);
			printf("%s\n",result);
		}
	}
down:
	return 0;
}
