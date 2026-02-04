#include<stdio.h>
//冒泡升序排序 ，程序的输入为 int类型数组 和数组长度 
//请在此处编辑您的代码
/**********  Begin  **********/
void bubble_sort(int *p,int n){
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10-i-1;j++){	
			if(*(p+j)>*(p+j+1)){
				int temp=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=temp;
			}
		}
	}
	return;
}
/**********  End  **********/
