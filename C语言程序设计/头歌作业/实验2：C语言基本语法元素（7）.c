#include <stdio.h>
int main(){
	char ch[80];
	gets(ch);//%s 只会读取到空格、制表符或换行符为止的字符串。
	int k;//gets(str) 会读取整行输入，直到遇到换行符 \n 为止。 
	scanf("d",&k);
	
	int i;
	for(i=0;ch[i]!='\0';i++){
		if(ch[i]>='A'&&ch[i]<='Z'){
			ch[i]=ch[i]+k-1;
		}
		while(ch[i]>'Z'){
			ch[i]=ch[i]-26;
		}
	}
	int m;
	for(m=0;ch[m]<i;m+=2){
		char temp=ch[m];
		ch[m]=ch[m+1];
		ch[m+1]=temp; 
	}
		printf("%s",ch);
		return 0;
}
