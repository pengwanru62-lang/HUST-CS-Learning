#include <stdio.h>
#include <stdlib.h>
void Rotate(int**matrix,int n,int m,int **rotated);
int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    int **matrix=(int**)malloc(n*sizeof(int*));
    if(matrix==NULL)return 1;
    int i,j;
    for(i=0;i<n;i++){
        matrix[i]=(int *)malloc(m*sizeof(int));
        if(matrix[i]==NULL) return 1;
    }
    int **rotated=(int**)malloc(m*sizeof(int*));
    if(rotated==NULL)return 1;
    for(i=0;i<m;i++){
        rotated[i]=(int *)malloc(n*sizeof(int));
        if(rotated[i]==NULL) return 1;
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&matrix[i][j]);
        }
    }

    Rotate(matrix,n,m,rotated);

    for(i=0;i<m;i++){
        free(rotated[i]);
    }
    free(rotated);

    for(i=0;i<n;i++){
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}

void Rotate(int **matrix,int n,int m,int **rotated){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            rotated[i][j]=matrix[j][m-1-i];
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d",rotated[i][j]);
            if(j<n-1)printf(" ");
        }
        printf("\n");
    }
    return;
}
