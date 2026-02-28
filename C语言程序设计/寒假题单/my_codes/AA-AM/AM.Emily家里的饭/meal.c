#include <stdio.h>

int main(){
    int t,n;
    scanf("%d %d",&t,&n);
    
    int time[105];
    int p[105];
    int earliest[105];
    int latest[105]; // 缺少这行

    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    
    for(int i=1;i<=n;i++){
        scanf("%d",&time[i]);
    }

    for(int i=1;i<=n;i++){
        if(p[i]==0)
            earliest[i]=1;
        else
            earliest[i]=time[p[i]]+earliest[p[i]];

        printf("%d ",earliest[i]);
    }
    printf("\n");

    for(int i=1;i<=n;i++){
        if(earliest[i]+time[i]-1>t) return 0;
    }

    for(int i=1;i<=n;i++){
        latest[i] = t - time[i] + 1;
    }

    for(int j=n;j>=1;j--){
        for(int i=1;i<=n;i++){
            if(p[i]==j){
                if(latest[j]+time[j]>latest[i])
                    latest[j] = latest[i] - time[j];
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(latest[i] < earliest[i])
            latest[i] = earliest[i];
    }

    for(int i=1;i<=n;i++){
        printf("%d ",latest[i]);
    }
    
    return 0;
}