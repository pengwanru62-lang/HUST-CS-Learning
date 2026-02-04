#include <stdio.h>
void inArray(int arr[],int n){
	int i;
	for (i=0;i<n;i++) scanf("%d",&arr[i]);
}

void selectSort(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		int j;
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void outArray(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
