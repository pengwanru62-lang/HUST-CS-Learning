#include <stdio.h>
#include <string.h>
void strcate(char t[],char s[]);
void strdelc(char t[],char c);
int main(){
	char a[100],b[100];
	char c;
	scanf("%s",a);
	scanf("%s",b);//缓存区可能还有换行符。 
	scanf(" %c",&c);// 这个空格的意思是：跳过前面所有的空白字符，直到遇到第一个非空白字符
	
	strcate(a,b);
	printf("%s\n",a);
	
	strdelc(a,c);
	printf("%s\n",a);
}

void strcate(char t[],char s[]){
	int i=0,j=0;
	while(t[i]) i++;
	while(s[j]){
		t[i++]=s[j++];
	}
	t[i]='\0';//添加字尾结束符 
}

void strdelc(char t[],char c){
		int j,k;
		for(j=0,k=0;t[j];j++){
			if(t[j]!=c) t[k++]=t[j];
		}
		t[k]='\0';
	}

