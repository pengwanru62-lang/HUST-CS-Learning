#include <stdio.h>

//请根据step3_main.cpp中的主函数流程，补全此函数
int digit(long n, int k)
{
	/**********  Begin  **********/
	long temp=n;
	int count=1;
	for(;temp/10!=0;count++) temp/=10;
	int i,ans;
	for(i=0;i<k;i++){
	    ans=n%10;
		n/=10;
	}
	if(k>count){return -1;}
	else {return ans;};
	
    /**********  End  **********/
}
    
