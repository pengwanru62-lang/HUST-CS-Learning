#include <stdio.h>

int isPrime(int n)
{
	if(n<=1)return 0;
	if(n==2)return 1;
	int i;
	for(i=2;i*i<=n;i++){
		if(n%i==0) return 0;
	}
	return 1;
}

void goldbach(int n)
//请完成goldbach函数，将大于等于4的偶数n表示成两个素数的和。
{
    /**********   Begin   **********/
    
        for (int i = 2; i <= n / 2; i++)
        {
            if (isPrime(i) && isPrime(n - i))
            {
                printf("%d=%d+%d", n, i, n - i);
                return;
            }
        }
    /**********    End    **********/
}
