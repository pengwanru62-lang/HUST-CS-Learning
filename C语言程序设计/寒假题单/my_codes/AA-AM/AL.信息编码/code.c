#include <stdio.h>

int main(){
    int n;
    long long m;

    scanf("%d %lld",&n,&m);
    
    int a[25];
    int b[25];

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++){
        b[i]=m%a[i];

        m=m/a[i];
    }

    for(int i=0;i<n;i++){
        printf("%d",b[i]);
        if(i!=n-1)printf(" ");
    }

    return 0;
}