#include <stdio.h>

int main(){
	int x,n;
	scanf("%d %d", &x, &n);
	/*先将n位移出，再将原来的低n位移回去*/
	x = ((unsigned int)x>>n) | (x<<(32-n));/*用unsigned int 类型转换从而实现逻辑移位 
											用n和32-n，相当于每个数都被遍历仅一次*/ 
	printf("%d",x); 
	return 0; 
}
