#include <stdio.h>
#include <stdbool.h> // for bool type
#include <string.h>  // for memset

// --- 建议使用的全局变量 ---
// n: 顶点数, m: 边数
int n, m;
// adj: 存储有向图的邻接矩阵
int adj[1001][1001];
// reach: 存储图的传递闭包（可达性矩阵）
int reach[1001][1001];


int main() {
    // 读取顶点数 n 和边数 m
    scanf("%d %d", &n, &m);

    // 初始化邻接矩阵
    memset(adj, 0, sizeof(adj));

    // 读取 m 条边并填充邻接矩阵
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    // result: 存储最终的连通性代码 (0, 1, 2, 3)
    int result = -1;

    /********** Begin **********/
    // 在此区域编写核心代码

    // 1. 计算可达性矩阵 `reach`
    //    - 可以使用 Floyd-Warshall 算法或者对每个顶点运行一次 BFS/DFS。
    //    - reach[i][j] = 1 表示从顶点 i 可以到达顶点 j。

    // 2. 检查强连通性 (Strongly Connected)
    //    - 遍历所有不同的顶点对 (i, j)。
    //    - 如果 reach[i][j] 和 reach[j][i] 均为 1，则 i 和 j 互相可达。
    //    - 如果所有顶点对都互相可达，则图是强连通的 (result = 3)。

    // 3. 如果不是强连通，检查单向连通性 (Unilaterally Connected)
    //    - 遍历所有不同的顶点对 (i, j)。
    //    - 如果 reach[i][j] 或 reach[j][i] 至少有一个为 1。
    //    - 如果所有顶点对都满足此条件，则图是单向连通的 (result = 2)。

    // 4. 如果不是单向连通，检查弱连通性 (Weakly Connected)
    //    - 构建该有向图的底层无向图（即忽略边的方向）。
    //    - 从任意一个顶点开始进行一次图遍历（BFS 或 DFS）。
    //    - 如果一次遍历可以访问到所有 n 个顶点，则图是弱连通的 (result = 1)。

    // 5. 如果以上都不是，则为非连通图 (result = 0)。
    //    - 将最终判断的结果存入 result 变量。
    int h[1001], to[1001], nxt[1001], cnt = 0;
    int uh[1001], uto[2002], unxt[2002], ucnt = 0;

    memset(h, 0, sizeof(h));
    memset(uh, 0, sizeof(uh));
    memset(reach, 0, sizeof(reach));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (adj[i][j]) {
                cnt++;
                to[cnt] = j;
                nxt[cnt] = h[i];
                h[i] = cnt;

                ucnt++;
                uto[ucnt] = j;
                unxt[ucnt] = uh[i];
                uh[i] = ucnt;

                ucnt++;
                uto[ucnt] = i;
                unxt[ucnt] = uh[j];
                uh[j] = ucnt;
            }
        }
    }

    int q[1001];

    for (int s = 1; s <= n; s++) {
        int front = 0;
        int rear = 0;

        reach[s][s] = 1;
        q[rear++] = s;

        while (front < rear) {
            int u = q[front++];

            for (int e = h[u]; e != 0; e = nxt[e]) {
                int v = to[e];

                if (!reach[s][v]) {
                    reach[s][v] = 1;
                    q[rear++] = v;
                }
            }
        }
    }

    bool strong = true;
    bool unilateral = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }

            if (!reach[i][j] || !reach[j][i]) {
                strong = false;
            }

            if (!reach[i][j] && !reach[j][i]) {
                unilateral = false;
            }
        }
    }

    if (strong) {
        result = 3;
    } else if (unilateral) {
        result = 2;
    } else {
        bool vis[1001];
        memset(vis, false, sizeof(vis));

        int front = 0;
        int rear = 0;

        vis[1] = true;
        q[rear++] = 1;

        while (front < rear) {
            int u = q[front++];

            for (int e = uh[u]; e != 0; e = unxt[e]) {
                int v = uto[e];

                if (!vis[v]) {
                    vis[v] = true;
                    q[rear++] = v;
                }
            }
        }

        bool weak = true;

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                weak = false;
                break;
            }
        }

        if (weak) {
            result = 1;
        } else {
            result = 0;
        }
    }



    /********** End **********/

    // 输出最终结果
    printf("%d\n", result);

    return 0;
}
