/*
鉴于此题代码难度较高，实现不易。
已经给出此题的完整做法，请仔细阅读并学习。
*/

#include <stdio.h>
#include <stdbool.h> // for bool type

// n: 顶点数
int n;
// g1: 图 G 的邻接矩阵
int g1[10][10];
// g2: 图 G' 的邻接矩阵
int g2[10][10];
// iso: 标记是否同构
bool iso = false;

// --- 辅助函数声明 ---
void gen(int *p, bool *used, int d);
bool check(int *p);

int main() {
    // 读取顶点数 n
    scanf("%d", &n);

    // 读取图 G 的邻接矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &g1[i][j]);
        }
    }

    // 读取图 G' 的邻接矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &g2[i][j]);
        }
    }

    // p: 用于存储排列
    int p[10];
    // used: 标记数字是否已用
    bool used[10] = {false};

    /********** Begin **********/
    // 任务是生成所有可能的顶点映射（排列），并检查是否满足同构条件。
    // 使用递归函数 gen 来完成。

    // 从深度 0 开始生成排列
    gen(p, used, 0);

    /********** End **********/

    // 根据标志位输出结果
    if (iso) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

// --- 实际的函数定义 ---

// 检查当前排列 p 是否为同构映射
bool check(int *p) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g1[i][j] != g2[p[i]][p[j]]) {
                return false;
            }
        }
    }
    return true;
}

// 递归生成所有排列并检查
void gen(int *p, bool *used, int d) {
    if (iso) { // 如果已找到，提前返回
        return;
    }
    if (d == n) { // 一个完整的排列已生成
        if (check(p)) {
            iso = true;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            p[d] = i;
            used[i] = true;
            gen(p, used, d + 1);
            used[i] = false; // 回溯
        }
    }
}
