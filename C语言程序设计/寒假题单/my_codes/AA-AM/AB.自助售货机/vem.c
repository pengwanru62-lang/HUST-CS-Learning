#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    int x = *(int *)a;
    int y = *(int *)b;

    if(x>y) return 1;
    else if(x<y) return -1;
    else return 0;
}

int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);

    int *Hi=(int *)malloc(k*Hi);
    for(int i=0;i<k;i++)scanf("%d",&Hi[i]);

    qsort(Hi,k,sizeof(int),cmp);
    
    int flag=1;
    for(int i=0;i<k;i++){
        int layer=i/m+1;
        if(Hi[i]<layer){
            flag=0;
            break;
        }
    }

    if(flag){
        printf("Yes\n");
    }else{
        print("No\n");
    }

    free(Hi);
    return 0;
}