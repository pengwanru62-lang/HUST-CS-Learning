#include <stdio.h>
#include <string.h>  // For memset
#include <stdbool.h> // For bool type

// 建议使用的全局/主要变量
// n: 顶点数, m: 边数
int n, m;
// ins: 存储每个顶点的入度
// out: 存储每个顶点的出度
int ins[100001];
int out[100001];



int main() {
    // 读取顶点数 n 和边数 m
    scanf("%d %d", &n, &m);

    // 读取 m 条边并计算每个顶点的出度和入度
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        out[u]++;
        ins[v]++;
    }

    // result: 存储最终结果 (0, 1, or 2)
    int result = 0;

    /********** Begin **********/
    // 在此区域编写核心代码。

    // 1. 检查顶点的度数
    //    - 遍历所有顶点（从 1 到 n）。
    //    - 统计满足 out[v] == ins[v] + 1 的顶点数 (记为 start)。
    //    - 统计满足 ins[v] == outs[v] + 1 的顶点数 (记为 end)。
    //    - 如果发现任何顶点的出入度之差的绝对值大于 1，则不可能构成欧拉通路或回路。

    // 2. 根据连通性和度数条件进行最终判断
    //    - 如果图是弱连通的，并且所有顶点的出度都等于入度，则为欧拉图 (result = 2)。
    //    - 如果图是弱连通的，并且 start == 1 且 end == 1，则存在欧拉通路 (result = 1)。
    //    - 其他所有情况（包括不连通或度数不满足上述两种情况），均不存在欧拉通路 (result = 0)。
    //    - 特例：如果没有边（m = 0），平凡图也算欧拉图 (result = 2)。
    int start = 0;
    int end = 0;
    bool bad = false;

    for (int i = 1; i <= n; i++) {
        if (out[i] == ins[i]) {
            continue;
        } else if (out[i] == ins[i] + 1) {
            start++;
        } else if (ins[i] == out[i] + 1) {
            end++;
        } else {
            bad = true;
        }
    }

    if (m == 0) {
        result = 2;
    } else if (bad) {
        result = 0;
    } else if (start == 0 && end == 0) {
        result = 2;
    } else if (start == 1 && end == 1) {
        result = 1;
    } else {
        result = 0;
    }




    /********** End **********/

    // 输出最终结果
    printf("%d\n", result);

    return 0;
}
