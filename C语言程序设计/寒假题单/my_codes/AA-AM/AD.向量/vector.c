#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    int **vec=(int **)malloc((n+1)*sizeof(int *));
    for(int i=0;i<=n;i++){
        vec[i]=(int *)malloc(m*sizeof(int));
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&vec[i][j]);
        }
    }

    for(int i=1;i<=n;i++){
        int ans=0;
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            int flag=1;
            for(int k=0;k<m;k++){
                if(vec[j][k]<=vec[i][k]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                ans=j;
                break;
            }
        }
        printf("%d\n",ans);
    }

    for(int i=0;i<=n;i++)free(vec[i]);
    free(vec);
    return 0;
}