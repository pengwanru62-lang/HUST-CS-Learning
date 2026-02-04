#include <stdio.h>
int main(){
	int a;
	scanf("%d", &a);
	int x = (a%3==0?(a%10==5?1:0):0);
	printf("%d",x);
	return 0;	
}
