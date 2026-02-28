#include <stdio.h>

int main(){
    int n,d;
    scanf("%d %d",&n,&d);


    int Q[10005][25];
    int K[10005][25];
    int V[10005][25];
    int W[10005];

    int M[25][25];
    int result[10005][25];

    //输入矩阵
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            scanf("%d",&Q[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            scanf("%d",&K[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            scanf("%d",&V[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        scanf("%d",&W[i]);
    }

//矩阵相乘
    //W x Q(n x d)
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            Q[i][j]*=W[i];
        }
    }

    //M = K^T V  (d × d)
    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++){
            M[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            long long tmp=K[i][j];
            for(int k=0;k<d;k++){
                M[j][k]+=tmp*V[i][j];
            }
        }
    }
    /*for(int i=0;i<d;i++){
        for(int j=0;j<d;j++){
            M[i][j]=0;
            for(int k=0;k<n;k++){
                M[i][j]+=K[k][i]*V[k][j];
            }
        }
    }*/
   //超时了优化后不会出现跨行访问的情况。


    // result = Q × M (n x d)
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            result[i][j]=0;
            for(int k=0;k<d;k++){
                result[i][j]+=Q[i][k]*M[k][j];
            }
        }
    }
    
    //输出矩阵
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
