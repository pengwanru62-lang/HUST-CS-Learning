#include <stdio.h>
#include <stdlib.h>

int main(){
    int N,M;
    scanf("%d %d",&M,&N);

    int *book=(int *)malloc(M*sizeof(int));
    int size=0;
    int head=0;
    int x;
    int ans=0;
    for(int i=0;i<N;i++){
        scanf("%d",&x);

        int found=0;
        for(int j=0;j<size;j++){
            if(book[j]==x){
                found=1;
                break;
            }
        }
        if(found)continue;
        ans++;
            if(size<M){
                book[size++]=x;
            }else{
                book[head]=x;
                head=(head+1)%M;
            }
    }
    printf("%d",ans);
    return 0;
}
