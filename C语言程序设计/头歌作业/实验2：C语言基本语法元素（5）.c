#include <stdio.h>
int IsScale(unsigned short m,unsigned short n){
	if(((m>=0)&&(m<=15))&&((n>=1)&&(n<=(16-m))))
		return 0;
	else
		return 1;
} 

int main(){
	unsigned short x,m,n;
	scanf("%hx %hu %hu",&x,&m,&n);
	if(IsScale(m,n)) {
		printf("ÊäÈë´íÎó");
		return 0; 	
	} 
	unsigned result=(x>>m) <<(16-n);
	printf("%hx\n",result);
	return 0;
}
