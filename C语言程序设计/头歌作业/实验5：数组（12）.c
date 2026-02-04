#include <stdio.h>
#include <stdlib.h>

int cnt=0;//计算路径数量
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void SetMaze(int n,int m,int **maze){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&maze[i][j]);
        }
    }
    return;
}

void PrintMaze(int n,int m,int **visit){
    cnt++;
    printf("%d\n",cnt);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d",visit[i][j]);
            if(j<m-1)printf(" ");
        }printf("\n");
    }
}

void dfs(int x,int y,int n,int m,int **maze,int **visit){
    visit[x][y]=1;
    if(x==n-1&&y==m-1){
        PrintMaze(n,m,visit);
        visit[x][y]=0;
        return;// 返回到调用者！！！
    }

    for(int i=0;i<4;i++){
        int tx=x+dx[i],ty=y+dy[i];
        if(tx<n&&tx>=0&&ty<m&&ty>=0&&maze[tx][ty]==1&&visit[tx][ty]==0){//防止数组越界访问
            dfs(tx,ty,n,m,maze,visit);
        }
    }
    visit[x][y]=0;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    int **maze=(int**)malloc(n*sizeof(int*));
    int **visit=(int**)malloc(n*sizeof(int*));

    for(int i=0;i<n;i++){
        maze[i]=(int*)malloc(m*sizeof(int));
        visit[i]=(int*)malloc(m*sizeof(int));
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visit[i][j]=0;//标记数组
        }
    }
    
    SetMaze(n,m,maze);
    dfs(0,0,n,m,maze,visit);

    for(int i=0;i<n;i++){
        free(maze[i]);
        free(visit[i]);
    }
    free(maze);
    free(visit);
    return 0;
}










