#include <stdio.h>
#include <stdbool.h> // for bool type

int main() {
    // n: 节点数
    int n;
    scanf("%d", &n);

    // sum: 存储度数总和
    long long sum = 0;
    // zerodeg: 标记是否存在度为0的节点
    bool zerodeg = false;

    // 读取 n 个度数，计算总和，并检查是否有度为0的节点
    for (int i = 0; i < n; i++) {
        int deg;
        scanf("%d", &deg);
        if (deg == 0) {
            zerodeg = true;
        }
        sum += deg;
    }

    // can_be_tree: 标记序列是否可以构成树，默认为 false
    bool can_be_tree = false;

    /********** Begin **********/
    // 在此区域根据可树序列定理进行判断

    // 1. 检查度数之和是否等于 2 * (n - 1)。
    //
    // 2. 如果 n > 1，还需要检查序列中是否存在度为 0 的节点。
    //    一棵含有两个或更多节点的树不能有度为 0 的孤立节点。
    //
    // 3. 综合以上条件，设置 can_be_tree 的值。
    //    (注意 n=1 是一个特殊的有效情况，其度数和为 0)
    if (n == 1) {
        can_be_tree = (sum == 0);
    } else {
        can_be_tree = (sum == 2LL * n - 2 && !zerodeg);
    }


    /********** End **********/

    // 根据 can_be_tree 标志位的值输出最终结果
    if (can_be_tree) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
