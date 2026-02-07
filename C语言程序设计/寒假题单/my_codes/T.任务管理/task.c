#include <stdio.h>
#include <string.h>

#define MAXN 5005

int graph[MAXN][MAXN];
int graphsize[MAXN];
int ans=0;
int visited[MAXN];

void dfs(int u){
    if(visited[u])return;
    visited[u]=1;
    ans++;

    for(int i=0;i<graphsize[u];i++){
        int v=graph[u][i];
        dfs(v);
    }
}

int main(){
    int N;
    scanf("%d",&N);

    memset(visited,0,sizeof(visited));
    memset(graphsize,0,sizeof(graphsize));

    for(int i=1;i<=N;i++){
        int Ci;
        scanf("%d",&Ci);

        for(int j=0;j<Ci;j++){
            int pre;
            scanf("%d",&pre);
            graph[i][graphsize[i]++]=pre;
        }
    }

    dfs(1);
    printf("%d",ans);
    return 0;
}
