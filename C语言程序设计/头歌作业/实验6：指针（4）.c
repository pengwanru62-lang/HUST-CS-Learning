#include <stdio.h>
#include <string.h>
int main() {
	char*(*p)(char a[],char b[]);
	char a[80],b[80],*result;
	int choice;
	while(1) {
		do {
			scanf("%d",&choice);

		} while(choice>4||choice<1);
		switch(choice) {
			case 1:
				p=strcpy;
				break;
			case 2:
				p=strcat;
				break;
			case 3:
				p=strtok;
				break;
			case 4:
				goto down;
		}
		getchar();
		fgets(a,sizeof(a),stdin);
		a[strcspn(a,"\n")]='\0';
		fgets(b,sizeof(b),stdin);
		b[strcspn(b,"\n")]='\0';
		result=p(a,b);
		printf("%s\n",result);
	}
down:
	return 0;
}
