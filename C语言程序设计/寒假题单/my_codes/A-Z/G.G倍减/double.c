#include <stdio.h>
int main(){
    int x;
    scanf("%d",&x);
    int y=2*x;
    int cnt=0;
    while(y!=1){
        y/=2;
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}