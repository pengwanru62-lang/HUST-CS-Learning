#include <stdio.h>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    int xi[105],yi[105];
    for(int i=0;i<n;i++){
        scanf("%d %d",&xi[i],&yi[i]);
    }

    int x[105],y[105];
    for(int i=0;i<m;i++){
        scanf("%d %d",&x[i],&y[i]);
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            x[i]+=xi[j];
            y[i]+=yi[j];
        }
        printf("%d %d\n",x[i],y[i]);
    }
}