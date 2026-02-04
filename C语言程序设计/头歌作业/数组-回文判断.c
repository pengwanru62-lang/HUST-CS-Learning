#include<stdio.h>
#include<string.h>

#define SIZE 100

int isPalindrome(char arr[],int len);

int main()
{
	/**** 输入字符串,调用函数isPalindrome判断是否为回文串，然后输出结果 *******/ 
    /**********  Begin ***********/
char str[SIZE];
scanf("%s",str);
int len=strlen(str);

if(isPalindrome(str,len))printf("Yes");
else if(!isPalindrome(str,len))printf("No");


	/**********  End  **********/
	return 0;
}

/**** 在下面编写满足任务要求的递归函数isPalindrome，是回文返回1，不是返回0 *******/ 
/**********  Begin ***********/
int isPalindrome(char arr[],int len){
	if(len<=1) return 1;
	if(arr[0]!=arr[len-1])return 0;//1和0的两个递归终止条件
	return(arr+1,len-2);//指针向后移动一位，长度缩小2 
}



/**********  End  **********/

