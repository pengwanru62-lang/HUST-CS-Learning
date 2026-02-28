#include <stdio.h>
#include <math.h>

int n,k;
int ans=0;
int x[20];

int is_prime(int num){
    if(num<2) return 0;
    if(num==2)return 1;
    if(num%2==0)return 0;

    for(int i=3;i<=sqrt(num);i+=2){
        if(num%i==0) return 0;
    }
    return 1;
}

void dfs(int start,int cnt,int sum){
    if(cnt==k){
        if(is_prime(sum)){
            ans++;
        }
        return;
    }
    if(start>=n)return;

    if(n-start<k-cnt) return;

    dfs(start+1,cnt+1,sum+x[start]); //选择当前数
    dfs(start+1,cnt,sum); //不选当前数
}

int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&x[i]);
    }
    
    dfs(0,0,0);
    
    printf("%d",ans);

    return 0;
}