#include <stdio.h>

#define MAX_TOTAL 1200

int min_time(int n,int times[]){
    int total=0;
    for(int i=0;i<n;i++){
        total+=times[i];
    }
    int dp[MAX_TOTAL+1]={0};
    dp[0]=1;

    for(int i=0;i<n;i++){
        int t=times[i];
        for(int j=total;j>=t;j--){
            if(dp[j-t]==1){
                dp[j]=1;
            }
        }
    }

    int half=total/2;
    for(int j=half;j>=0;j--){
        if(dp[j]==1){
            return (j>total-j)?j:(total-j);
        }
    }
    return total;
}

int main(){
    int s[4];
    for(int i=0;i<4;i++) scanf("%d",&s[i]);

    int total=0;
    for(int i=0;i<4;i++){
        int n=s[i];
        int times[20];
        for(int j=0;j<n;j++){
            scanf("%d",&times[j]);
        }
        total+=min_time(n,times);
    }
    printf("%d",total);
}