#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	
	int m=0,ans=0,i=0,pre;
	pre=n;
	do{
		m=n%10;
		ans+=m;
		n=n/10;
		i++;
	} while(n!=0); 
	
	printf("%d是%d位数，且各位数字之和为%d。",pre,i,ans);
	return 0;	
}
