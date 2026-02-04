#include <stdio.h>
#include <math.h>

int iscomposite(int x){
    if(x<4) return 0;
    int i;
    for(i=2;i*i<=x;i++){
        if(x%i==0) return 1;
    }
    return 0;
}

int ispurecomposite(int x){
    int temp=x;
    while(temp!=0){
        if(!iscomposite(temp)) return 0; 
        temp/=10;
    }
    
    return 1;
}

int main(){
    int n;
    scanf("%d",&n);
    int max=pow(10,n);
    int min=pow(10,n-1);
    int i=min;
    for (i;i<max;i++){
        if(ispurecomposite(i)) printf("%d ",i);
    }
    return 0;
}
