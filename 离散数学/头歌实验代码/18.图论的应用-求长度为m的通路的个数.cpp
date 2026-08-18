#include <stdio.h>
#include <string.h> // For memcpy and memset

int main() {
    // n: 结点数
    int n;
    scanf("%d", &n);

    // adj: 邻接矩阵 A
    long long adj[15][15];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &adj[i][j]);
        }
    }

    // m: 通路长度
    int m;
    scanf("%d", &m);

    // res: 存 A ^ m 矩阵
    long long res[15][15];
    // tmp: 临时矩阵
    long long tmp[15][15];
    // sum: 通路总数
    long long sum = 0;

    /********** Begin **********/
    // 在此区域计算邻接矩阵的 m 次幂 (A^m)
    // 并将结果存入 res 矩阵
    memcpy(res, adj, sizeof(adj));

    for (int step = 1; step < m; step++) {
        memset(tmp, 0, sizeof(tmp));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (res[i][k] == 0) {
                    continue;
                }

                for (int j = 0; j < n; j++) {
                    tmp[i][j] += res[i][k] * adj[k][j];
                }
            }
        }

        memcpy(res, tmp, sizeof(tmp));
    }



    /********** End **********/

    // 计算 res (即 A^m) 中所有元素的总和
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += res[i][j];
        }
    }

    // 输出最终的通路总数
    printf("%lld\n", sum);

    return 0;
}
