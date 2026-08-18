#include <stdio.h>
#include <string.h> // For memset

int main() {
    // n: 图的顶点数, m: 图的边数
    int n, m;
    scanf("%d %d", &n, &m);

    // adj: 存储 n x n 的邻接矩阵
    int adj[50][50];
    // 将矩阵所有元素初始化为 0
    memset(adj, 0, sizeof(adj));

    /********** Begin **********/
    // 在此区域编写核心代码
    // 1. 循环 m 次，读取所有的边。
    // 2. 在每次循环中，读取边的两个端点 u 和 v。
    // 3. 根据读取到的有向边 <u, v>，在邻接矩阵中进行标记。
    //    由于顶点编号从 1 开始，而数组下标从 0 开始，
    //    所以需要将 adj[u - 1][v - 1] 的值置为 1。
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u - 1][v - 1] = 1;
    }




    /********** End **********/

    // 输出最终的 n x n 邻接矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
