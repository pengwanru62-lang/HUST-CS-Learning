#include <stdio.h>

int main() {
    // 变量 n, m 分别表示集合 A, B 的大小
    int n, m;
    scanf("%d %d", &n, &m);

    // 数组 setA 用于存储集合 A 的元素
    int setA[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &setA[i]);
    }

    // 数组 setB 用于存储集合 B 的元素
    int setB[100];
    for (int i = 0; i < m; i++) {
        scanf("%d", &setB[i]);
    }

    /********** Begin **********/
    // 在此区域编写核心代码
    // 1. 遍历集合 A 中的每一个元素。
    // 2. 对于 A 中的每一个元素，再遍历集合 B 中的所有元素。
    // 3. 按照 "A 中元素 B 中元素" 的格式输出序偶，每个序偶占一行。

    // 1. 遍历集合 A 中的每一个元素。
    for(int i=0; i<n; i++)
    {
        // 2. 对于 A 中的每一个元素，再遍历集合 B 中的所有元素。
        for(int j=0; j<m; j++)
        {
            // 3. 按照 "A 中元素 B 中元素" 的格式输出序偶，每个序偶占一行。
            printf("%d %d\n", setA[i], setB[j]);
        }
    }
    /********** End **********/

    return 0;
}