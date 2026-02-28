#include <stdio.h>
#include <math.h>

int main(){
    int q;
    scanf("%d",&q);

    while(q--){
        long long a;
        int k;
        scanf("%lld %d",&a,&k);

        long long result=1;
        int i;
        for(i=2;i<=sqrt(a);i++){    
            int cnt=0;
            while(a%i==0){
                cnt++;
                a/=i;
            }
            if(cnt>=k){
                for(int j=0;j<cnt;j++){
                    result*=i;
                }
            }
        }
    if(a>1){
        if(k<=1){
            result*=a;
        }
    }

        printf("%lld\n",result);
    }
    return 0;
}