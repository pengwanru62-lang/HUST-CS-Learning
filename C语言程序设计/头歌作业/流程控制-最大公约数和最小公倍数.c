#include <stdio.h>

int gcd(int x,int y);
int lcm(int x,int y);
int main(){
	int a,b;
	scanf("%d %d", &a,&b);
	printf("%d %d",gcd(a,b),lcm(a,b));
	return 0;
}

int gcd(int x,int y){
	int tmp;
	while(y!=0){
		tmp=x%y;
		x=y;
		y=tmp;
	}
	return x;
} 

int lcm(int x,int y){
	int tmp;
	tmp = gcd(x,y);
	int r = x*y/tmp;
	return r;
}
