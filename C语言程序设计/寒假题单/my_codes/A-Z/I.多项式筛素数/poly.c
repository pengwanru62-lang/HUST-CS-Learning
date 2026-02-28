#include <stdio.h>
#include <math.h>
int main(){
    int S;
    scanf("%d",&S);
    if(S<2){
        printf("0");
        return 0;
    }
    int sum=2,cnt=1; // 已选中质数 2
    printf("2\n");
    for(int i=3; ; i++){
        int flag=0;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(!flag){
            if(sum + i > S) break; // 超过上限则停止
            printf("%d\n",i);
            sum+=i;
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}