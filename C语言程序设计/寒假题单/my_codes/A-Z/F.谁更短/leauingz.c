#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int Z=3*n+11;
    int L=5*n;
    if(Z>L)printf("Local");
    else printf("Luogu");
    return 0;
}