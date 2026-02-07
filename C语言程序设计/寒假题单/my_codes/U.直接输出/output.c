#include <stdio.h>

void print(int n){
    if(n==0){
        printf("0");
        return;
    }

    int first=1;
    for(int k=31;k>=0;k--){
        if(n&(1<<k)){
            if(!first){
                printf("+");
            }
            first=0;
            if(k==0){
                printf("2(0)");
            }else if(k==1){
                printf("2");
            }else{
                printf("2(");
                print(k);
                printf(")");
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    print(n);
    return 0;
}