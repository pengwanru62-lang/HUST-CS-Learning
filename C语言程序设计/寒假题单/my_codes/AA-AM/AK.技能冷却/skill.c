#include <stdio.h>

long long t[100005];
long long c[100005];

int main(){
    long long n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);

    long long max_t=0;
    
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&t[i],&c[i]);
        if(t[i]>max_t){
            max_t=t[i];
        }
    }
    
    long long left=k;
    long long right=max_t;
    long long mid;
    long long ans=0;

    while(left<=right){
        mid=(left+right)/2;

        long long total_cost=0;

        for(int i=0;i<n;i++){
            if(t[i]>mid){
                total_cost+=(t[i]-mid)*c[i];
            }
            if(total_cost>m)break;
        }
        if(total_cost<=m){
            ans=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    printf("%lld\n",ans);
    return 0;
} 