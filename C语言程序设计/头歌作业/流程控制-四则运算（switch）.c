#include <stdio.h>

int main(){
	double a,b,ans;
	char c;
	scanf("%lf %lf %c",&a,&b,&c);
	
	switch(c){
		case '+':
			ans=a+b;
			break;
		case '-':
			ans=a-b;
			break;
		case '*':
			ans=a*b;
			break;
		case '/':
			ans=a/b;
			break;
		default:
			printf("error");
			break;
	}
	printf("%.1f",ans);
	return 0;
}
