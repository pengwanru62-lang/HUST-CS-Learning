#include <stdio.h>
#include <math.h>
int main(){
	int day;
	scanf("%d",&day);
	
	int arry[day];
	int i;
	for(i=0;i<day;i++){
		scanf("%d",&arry[i]);
	}
	
	int max=0;
	int k;
	for(k=0;k<day-1;k++){
		if( (abs ( arry[k] - arry[k+1] )) > max )
			max=abs ( arry[k] - arry[k+1] );
	}
	printf("%d",max);
	return 0;
}
