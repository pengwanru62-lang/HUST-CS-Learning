#include <stdio.h>
#include <string.h>
void RemoveDuplicate(char *s);

int main(){
	char str[200];
	while(fgets(str,200,stdin)!=NULL){
		RemoveDuplicate(str);
		printf("%s",str);	
	}
	return 0;
} 

void RemoveDuplicate(char *s){
	int a[200]={1};
	int i,k;
	for (i=0,k=0;i<strlen(s);i++){
		if(a[i]){
			a[1]=0;
			s[k++]=s[i];
		}
	}
	s[k]='\0';
}
