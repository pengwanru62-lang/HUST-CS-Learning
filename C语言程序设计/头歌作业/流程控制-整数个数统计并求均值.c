#include <stdio.h>
int main(){
	
	int count=0,i=0,sum=0,x;
	for(;i<=10;i++){
		scanf("%d",&x);
		if (x<=0) continue;
		++count;
		sum+=x;
	}
	if (count!=0){
	double aver=(double)sum/count;
		printf("numbers=%d, average=%.6f",count,aver);
	}else{
		printf("numbers=0, average=0");
	}

	return 0;
}
