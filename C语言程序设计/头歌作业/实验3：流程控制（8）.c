#include <stdio.h>
int main(){
	char c1;
	char c0=0;
	while((c1=getchar())!=EOF){//注意=运算符的优先级问题 
		if(c1==' '){
			if(c0!=' ') putchar(' ');
		}else{
			putchar(c1);
		}
		c0=c1;
	}
	return 0;
}
