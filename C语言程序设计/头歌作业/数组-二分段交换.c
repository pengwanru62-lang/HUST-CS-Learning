#include <stdio.h>

void move(int arr[],int n,int k){
	//前半段反转
	int i,j;
	for(i=0,j=k-1;i<j;i++,j--){
		int temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	} 
	
	//后半段反转
	for(i=k,j=n-1;i<j;i++,j--){
		int temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	} 
	
	//整个数组反转
	 	for(i=0,j=n-1;i<j;i++,j--){
		int temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	} 
}
