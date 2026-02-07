#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b){
    int x=*(const int *)a;
    int y=*(const int *)b;
    if(x<y)return -1;
    if(x>y)return 1;
    return 0;
}

//第一个>=target的left位置
int lower_bound(int arr[],int n,int target){
    int left=0,right=n;
    while(left<right){
        int mid=left+(right-left)/2;
        if(arr[mid]<target){
            left=mid+1;
        }else{
            right=mid;
        }
    }
    return left;
}

//第一个>target的left位置
int upper_bound(int arr[],int n,int target){
    int left=0,right=n;
    while(left<right){
        int mid=left+(right-left)/2;
        if(arr[mid]<=target){
            left=mid+1;
        }else{
            right=mid;
        }
    }
    return left;
}

void Q1(int x,int arr[],int n){
    int left=lower_bound(arr,n,x);
    int right=upper_bound(arr,n,x);
    printf("%d\n",right-left);
}

void Q2(int x,int y,int arr[],int n){
    if(x>y){
        printf("0\n");
        return;
    }
    int left=lower_bound(arr,n,x);
    int right=upper_bound(arr,n,y);
    printf("%d\n",right-left);
}

void Q3(int x,int y,int arr[],int n){
    if(x>=y){
        printf("0\n");
        return;
    }
    int left=lower_bound(arr,n,x);
    int right=lower_bound(arr,n,y);
    printf("%d\n",right-left);
}

void Q4(int x,int y,int arr[],int n){
    if(x>=y){
        printf("0\n");
        return;
    }
    int left=upper_bound(arr,n,x);
    int right=upper_bound(arr,n,y);
    printf("%d\n",right-left);
}

void Q5(int x,int y,int arr[],int n){
    if(x>=y){
        printf("0\n");
        return;
    }
    int left=upper_bound(arr,n,x);
    int right=lower_bound(arr,n,y);
    printf("%d\n",right-left);
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int *arr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    qsort(arr,n,sizeof(int),compare);


    for(int i=0;i<m;i++){
        int choice;
        scanf("%d",&choice);
        int x,y;
        switch(choice){
            case 1:
                scanf("%d",&x);
                Q1(x,arr,n);
                break;
            case 2:
                scanf("%d %d",&x,&y);
                Q2(x,y,arr,n);
                break;
            case 3:
                scanf("%d %d",&x,&y);
                Q3(x,y,arr,n);
                break;
            case 4:
                scanf("%d %d",&x,&y);
                Q4(x,y,arr,n);
                break;
            case 5:
                scanf("%d %d",&x,&y);
                Q5(x,y,arr,n);
                break;
        }
    }
    free(arr);
    return 0;
}