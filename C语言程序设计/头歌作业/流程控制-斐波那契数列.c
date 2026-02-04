#include <stdio.h>
int main() {
	int n;
	scanf("%d",&n);

	if(n<20) {
		printf("error input!");
		return 1;
	}

	long long fib[n];
	fib[0]=1;
	fib[1]=1;

	int i;
	for(i=2; i<n; i++) {
		fib[i]=fib[i-1]+fib[i-2];
	}

	int k;
	for(k=0; k<n; k++) {
		printf("%10lld",fib[k]);

		if((k+1)%8==0) {
			printf("\n");
		}//如果换行判断在循环外面，这样只能判断最后一个数是否需要换行，而不能实现每8个数换行的效果。
	}
	return 0;
}
