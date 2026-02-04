#include <stdio.h>
int main(void){
	int a[100],b[100];
	int i,j,k,M,N;
	scanf("%d %d",&M,&N);
	for(i=0;i<M;i++){
		a[i]=i+1;
	}//一共有多少个人，每个人的序号 第0对第一，M表示参加游戏的人数
	for(i=M,j=0;i>1;i--) //j表示选出去的人，N表示你喊的数字
	{
		for(k=1;k<=N;k++)
		{
			j++;//喊一个加一个1
			if(j>i-1) j=0;//喊完一轮重置 
		 } 
	  
	 b[M-i]=(j?a[j-1]:a[i-1]);//如果是0，到头输出i-1 
	if(j)
	for(k=--j;k<i;k++)//缩减数组，将每一次死的人排出去
	a[k]=a[k+1];
	}
	for(i=0;i<M-1;i++){
		printf("%6d",b[i]);
	}
	printf("\n%6d\n",a[0]);
	 return 0;
	
}
