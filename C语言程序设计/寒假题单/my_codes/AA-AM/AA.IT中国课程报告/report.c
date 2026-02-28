#include <stdio.h>
#include <stdlib.h>

int cmp(void const *a,void const *b){
    int x = *(int *)a;
    int y = *(int *)b;

    if(x>y) return -1;
    else if(x<y) return 1;
    else return 0;
}

int main(){
    int N,B;
    scanf("%d %d",&N,&B);

    int *Hi=(int *)malloc(N*sizeof(int));
    for(int i=0;i<N;i++){
        scanf("%d",&Hi[i]);
    }

    qsort(Hi,N,sizeof(int),cmp);

    int sum=0;
    int cnt=0;
    for(int i=0;i<N;i++){
        cnt++;
        sum+=Hi[i];
        if(sum>=B) break;
    }

    printf("%d\n",cnt);

    free(Hi);
    return 0;
}