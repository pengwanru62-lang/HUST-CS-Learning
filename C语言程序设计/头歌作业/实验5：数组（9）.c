#include <stdio.h>
#include <string.h>
void strnins(char t[],char s[],int n);
int main(){
	char s[100];
	char t[100];
	int n;
	scanf("%s",t);
	scanf("%s",s);
	scanf("%d",&n);
	
	strnins(t,s,n);
	printf("%s\n", t); 
}
void strnins(char t[],char s[],int n){
	int k;
	char temp[100];
	strcpy(temp,t);
	int i,j;
	for(i=n,j=0;s[j]!='\0';i++,j++){
		t[i]=s[j];
	}
	int m=strlen(s);
	int l,r;
	for(l=n+m,r=n;temp[r]!='\0';l++,r++){
		t[l]=temp[r];
	}
	int h=strlen(temp)+m;
	t[h]='\0';
	return;
}
