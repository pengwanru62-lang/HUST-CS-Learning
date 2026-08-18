#include <stdio.h>
#include <stdlib.h>  // for qsort
#include <stdbool.h> // for bool type

// 比较函数，用于 qsort 降序排序
int compare_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    // n: 序列的当前长度
    int n;
    scanf("%d", &n);

    // deg: 存储度数序列
    int deg[100], sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &deg[i]);
        sum += deg[i];
    }

    // is_graphic: 标记序列是否可图，默认为 true
    bool is_graphic = true;

    /********** Begin **********/
    // 此区域实现 Havel-Hakimi 算法
    if (sum % 2 != 0) {
        is_graphic = false;
    }

    while (is_graphic) {
        qsort(deg, n, sizeof(int), compare_desc);

        if (deg[0] == 0) {
            break;
        }

        int d = deg[0];

        if (d < 0 || d >= n) {
            is_graphic = false;
            break;
        }

        deg[0] = 0;

        for (int i = 1; i <= d; i++) {
            deg[i]--;

            if (deg[i] < 0) {
                is_graphic = false;
                break;
            }
        }
    }


    /********** End **********/

    // 根据 is_graphic 标志位的值输出最终结果
    if (is_graphic) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
