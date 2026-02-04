#include <stdio.h>
int main() {
	double a,b,ans;
	char c;

	scanf("%lf %lf %c",&a,&b,&c);//double输入用lf输出用f 
	 
	if(c=='+') {
		ans = a + b;
	} else if(c=='-') {
		ans = a - b;
	} else if(c=='*') {
		ans = a * b;
	} else if(c=='/') {
		ans = a / b;
	}
	printf("%.1f", ans);
	return 0;
}
