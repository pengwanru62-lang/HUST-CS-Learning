//第一个文件
#include<stdio.h>
#include"file.h"
int x,y;
char ch;
int main(void)
{
	x=10;
   y=20;
   ch=getchar();
   printf("in file1 x=%d,y=%d,ch is %c\n",x,y,ch);
	func1();
	return 0;
}
//第二个文件 
#include"file.h"
void func1(void)
{
	x++;
	y++;
	ch++;
	printf("in file2 x=%d,y=%d,ch is %c\n",x,y,ch);
}
//第三个文件
 /*****编写该头文件*****/
#include <stdio.h>
void func1(void);
extern int x, y;
extern char ch;

