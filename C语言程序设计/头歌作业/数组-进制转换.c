#include<stdio.h>

void conversion(char str[]){
	/**********  Begin  **********/
	int i;
	int sum=0;
	int x;
	for(i=0;(str[i]!='\0')&&(str[i]>='0'&&str[i]<='9'||str[i]>='A'&&str[i]<='F'||str[i]>='a'&&str[i]<='f');i++){
		x=str[i];
		if(str[i]>='0'&&str[i]<=9){
			sum=sum*16+(x-'0');
		}else if(str[i]>='A'&&str[i]<='F'){
			sum=sum*16+(x-'A'+10);
		}else if(str[i]>='a'&&str[i]<='f'){
			sum=sum*16+(x-'a'+10);	
		}
	}
	printf("%d",sum);

	/**********  End  **********/
}
