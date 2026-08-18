#include <stdio.h>
#include <string.h> // For memset

int main() {
    // n: 顶点数, m: 边数
    int n, m;
    scanf("%d %d", &n, &m);

    // adj: 存储原始图 G 的邻接矩阵
    int adj[50][50];
    memset(adj, 0, sizeof(adj));

    // 读取 m 条边并填充邻接矩阵
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u - 1][v - 1] = 1;
    }

    // k: 导出子图的点集 V2 的大小
    int k;
    scanf("%d", &k);

    // comp: 存储补图 G_bar 的邻接矩阵
    int comp[50][50];

    /********** Begin **********/
    // 在此区域编写核心代码

    // 1. 计算补图的邻接矩阵 (comp)
    //    a. 遍历一个 n x n 的矩阵。
    //    b. 对于每个位置 (i, j):
    //       - 如果 i == j (主对角线), 补图中没有自环, comp[i][j] = 0。
    //       - 如果 i != j, 检查原始图中是否存在边 <i+1, j+1>。
    //       - 如果 adj[i][j] == 0, 说明原始图没有这条边, 那么补图就有, comp[i][j] = 1。
    //       - 如果 adj[i][j] == 1, 说明原始图有这条边, 那么补图就没有, comp[i][j] = 0。

    // 2. 导出子图的邻接矩阵可以直接从 adj 的左上角 k x k 部分获得，
    //    无需在此处额外计算，在输出部分直接使用即可。

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                comp[i][j] = 0;
            } else {
                comp[i][j] = 1 - adj[i][j];
            }
        }
    }

    /********** End **********/

    // 输出补图的邻接矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", comp[i][j]);
        }
        printf("\n");
    }

    // 输出一个空行
    printf("\n");

    // 输出 V2 导出的子图的邻接矩阵 (adj 的左上角 k x k 部分)
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
