#include <stdio.h>
#include <string.h>
#include <math.h>
//提取p的i位二进制数 
int getbit(char p,int i){
	int n=p/(int)pow(2,i)%2;//p除以2的i次方相当于把p的二进制向右移动i位，除以二提取末尾的数 
	return n; 
}

//进行加密过程 
char encrypt(char p){
	int i;
	int ch[6];
	for(i=0;i<6;i+=2){
		ch[i+1]=getbit(p,i);//move将p的第i位提取出来并且储存在i+1位；
		ch[i]=getbit(p,i+1); 
	}
	
	int n=getbit(p,6)+2*getbit(p,7);//计算移动多少位
	
	int arry[8];
	arry[6]=getbit(p,6);//第六位和第七位的数组保持不变 
	arry[7]=getbit(p,7);
	
	int k;
	for(k=0;k<6;k++){
		arry[(k+n)%6]=ch[k];//移动奇偶变换后的数字并存放在arry中 
	} 
	
	char new=0;//重新复原 
	int m;
	for(m=0;m<8;m++){
		new+=arry[m]*pow(2,m);
	}
	return new; 
}

int main(){
	char ch[20];
	scanf("%s",ch);
	int i;
	for(i=0;i<strlen(ch);i++){
		ch[i]=encrypt(ch[i]);
	}
	printf("%s",ch);
	return 0;
}
