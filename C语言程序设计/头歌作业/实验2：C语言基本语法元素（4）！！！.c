#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int IsNum(char ch[]){
	int i;
	for(i=0;i<strlen(ch);i++){
		if(ch[i]<'0'||ch[i]>'9')
		return 1;
	}
	return 0;
}

int main(){
	char ch[20];
	while(scanf("%s",ch)!=EOF){
		if(strlen(ch)!=11){
			printf("长度不合法"); 
		}else if(IsNum(ch)){
			printf("字符串中存在非数字字符"); 
		}else if(ch[0]!='1'){
			printf("第1位不合法"); 
		}else if(ch[1]!='3'&&ch[1]!='4'&&ch[1]!='5'&&ch[1]!='7'&&ch[1]!='8'){
			printf("第2位不合法"); 
		}
		return 0;
	}
}
