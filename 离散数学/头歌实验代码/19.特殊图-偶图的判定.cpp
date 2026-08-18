#include <stdio.h>
#include <string.h>  // For memset
#include <stdbool.h> // For bool type

// --- 邻接表所需的数据结构 ---
// 边结构体
struct Edge {
    int to;
    int next;
};

// 边数组
struct Edge edges[200002];
int head[100001];
int e_cnt;

// 添加边的函数
void add(int u, int v) {
    e_cnt++;
    edges[e_cnt].to = v;
    edges[e_cnt].next = head[u];
    head[u] = e_cnt;
}


int main() {
    // n: 顶点数, m: 边数
    int n, m;
    scanf("%d %d", &n, &m);

    // color: 存储顶点颜色 (0:未染, 1 / 2:两种颜色)
    int color[100001];
    memset(color, 0, sizeof(color));

    // 读取 m 条边并构建邻接表
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
    }

    // is_bipartite: 标记是否为偶图
    bool is_bipartite = true;

    /********** Begin **********/
    // 在此区域使用二染色法判断图是否为偶图
    int queue[100001];

    for (int s = 1; s <= n && is_bipartite; s++) {
        if (color[s] != 0) {
            continue;
        }

        color[s] = 1;

        int front = 0;
        int rear = 0;
        queue[rear++] = s;

        while (front < rear && is_bipartite) {
            int u = queue[front++];

            for (int i = head[u]; i != 0; i = edges[i].next) {
                int v = edges[i].to;

                if (color[v] == 0) {
                    color[v] = 3 - color[u];
                    queue[rear++] = v;
                } else if (color[v] == color[u]) {
                    is_bipartite = false;
                    break;
                }
            }
        }
    }

    /********** End **********/

    // 根据 is_bipartite 标志位的值输出最终结果
    if (is_bipartite) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
