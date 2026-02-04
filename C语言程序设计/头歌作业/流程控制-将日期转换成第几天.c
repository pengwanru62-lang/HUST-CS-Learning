#include <stdio.h>

int main(){
	int year,month,day;
	int total=0;
	int i;
	int monthdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d %d %d",&year,&month,&day);
    
	if((year%4==0&&year%100!=0)||(year%400==0)){//判断不是赋值！！！ 
		monthdays[1] = 29;	
	}
	for(i=0;i<month-1;i++){//使用分号！！！ 
		total+=monthdays[i];
	}
	total+=day;
	printf("%d",total);
	return 0;
}
