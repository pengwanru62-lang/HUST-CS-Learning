#include <stdio.h>
#include <string.h>

long long memo[100];

long long fab(int i){
    if(i<=2)return 1;
    if(memo[i]!=-1)return memo[i];
    memo[i]=fab(i-1)+fab(i-2);
    return memo[i]=fab(i-1)+fab(i-2); 
}

int main(){
    int n;
    scanf("%d",&n);
    long long sum=0;
    memset(memo,-1,sizeof(memo));
    for(int i=1;i<=n;i++){
        sum+=fab(i);
    }
    printf("%lld",sum);
    return 0;

}
