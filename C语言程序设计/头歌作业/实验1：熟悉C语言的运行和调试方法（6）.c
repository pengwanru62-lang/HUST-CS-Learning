#include<stdio.h>
void strReverse(char s[]); 
int strLength(char s[]);
int main() 
{
	char s[1000];
	printf("输入一个字符串\n");
	scanf("%s",s);
	strLength(s); 
	printf("串%s的长度为:%d\n",s,strLength(s));
	strReverse(s);  
	printf("反转后:%s",s);
	return 0;
}

int strLength(char s[])  /* 返回字符串的长度（不含串尾）*/ 
{
	int i=0;
	while(s[i]) i++;//s[i++]访问5但是i是变成了6输出 
	return i; 	
}

void strReverse(char s[])  /* 反转串s */
{
	int i,j;
	for(i=0,j=strLength(s)-1;i<j;i++,j--)  /* 从两头遍历s */
	{
	    char t;
		t=s[i]; 
	    s[i]=s[j]; 
	    s[j]=t; 
    }
}
