#include <stdio.h>

#define MOD 998244353

typedef struct{
    long long m[3][3];
}Matrix;

//矩阵乘法
Matrix multiply(Matrix A, Matrix B){
    Matrix C;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            C.m[i][j]=0;
            for(int k=0;k<3;k++){
                C.m[i][j]=(C.m[i][j]+((A.m[i][k]%MOD) * (B.m[k][j]))%MOD)%MOD;
            }
        }
    }
    return C;
}

//矩阵快速幂
Matrix power(Matrix A,long long n){
    Matrix result;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            result.m[i][j]=(i==j);
        }
    }

    while(n>0){
        if(n&1)result=multiply(result,A);
        A=multiply(A,A);
        n>>=1;
    }
    return result;
}

int main(){
    long long n;
    scanf("%lld",&n);

    long long f1,f2;
    scanf("%lld %lld",&f1,&f2);

    long long a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);

    if(n==1){
        printf("%lld",f1%MOD);
        return 0;
    }
    if(n==2){
        printf("%lld",f2%MOD);
        return 0;
    }

    Matrix A;
    A.m[0][0]=a; A.m[0][1]=b; A.m[0][2]=c;
    A.m[1][0]=1; A.m[1][1]=0; A.m[1][2]=0;
    A.m[2][0]=0; A.m[2][1]=0; A.m[2][2]=1;

    Matrix An=power(A,n-2);

    long long fn=(
        An.m[0][0]*f2%MOD +
        An.m[0][1]*f1%MOD +
        An.m[0][2]%MOD
    )%MOD;

    printf("%lld",fn);
    return 0;
}