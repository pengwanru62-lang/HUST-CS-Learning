#include <stdio.h>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    int board[100][100];
    int mark[100][100]={0};

    int i,j;

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&board[i][j]);
        }
    }

    for(i=0;i<n;i++){
        j=0;
        while(j<m){
            int temp=board[i][j];
            int count=1;
            int k=j+1;
            for(k;board[i][k]==temp&&k<m;k++){
                count++;
            }
            if(count>=3){
                int t;
                for(t=j;t<j+count;t++){
                    mark[i][t]=1;
                }
            }
            j+=count;
        }
    }
    
    for(j=0;j<m;j++){
        i=0;
        while(i<n){
            int temp=board[i][j];
            int count=1;
            int k=i+1;
            for(k;board[k][j]==temp&&k<n;k++){
                count++;
            }
            if(count>=3){
                int t;
                for(t=i;t<i+count;t++){
                    mark[t][j]=1;
                }
            }
            i+=count;
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(mark[i][j]){
                board[i][j]=0;
            }
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d",board[i][j]);
            if(j<=m-2) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
