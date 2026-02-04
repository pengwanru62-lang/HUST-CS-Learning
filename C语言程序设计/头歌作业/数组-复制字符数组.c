#include<stdio.h>

void strnCpy(char t[],char s[],int n){
	/**********  Begin  **********/
    
	int i;
	for(i=0;i<n;i++){	
		t[i]=s[i];
	}
    //为了让字符合法，结束为'\0'
    t[n]='\0';

	/**********  End  **********/
}


