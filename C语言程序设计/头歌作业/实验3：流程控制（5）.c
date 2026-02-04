#include <stdio.h>
int main(){
	int x;
	scanf("%d",&x);
	
	int level=x/1000;
	switch(level){
		case 0:
			printf("0");
			break;
		case 1:
			printf("%d",(int)((x-1000)*0.05));
			break;
		case 2:
			printf("%d",(int)((x-2000)*0.10+50));
			break;
		case 3:
			printf("%d",(int)((x-3000)*0.15+150));
			break;
		case 4:
			printf("%d",(int)((x-4000)*0.20+300));
			break;
		default:
			printf("%d",(int)((x-5000)*0.25+500));
			break;			
	}
	return 0;
} 
