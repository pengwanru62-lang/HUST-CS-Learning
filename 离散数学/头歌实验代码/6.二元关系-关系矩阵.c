#include <stdio.h>
#include <string.h>

int main() {
    // n: 集合 A 的大小, m: 集合 B 的大小, k: 关系 R 中的序偶数量
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    // relationMatrix: 存储 n x m 的关系矩阵 M_R
    int relationMatrix[100][100];
    
    // 默认情况下关系不存在，因此将矩阵所有元素初始化为 0
    memset(relationMatrix, 0, sizeof(relationMatrix));

    /********** Begin **********/
    // 在此区域编写核心代码
    // 1. 循环 k 次，读取所有的序偶
    // 2. 对于读入的每一个序偶 <u, v>
    // 3. 将 relationMatrix[u - 1][v - 1] 的值置为 1
    //    (注意：题目输入的 u, v 是从 1 开始的，而数组下标是从 0 开始的)

    // 1. 循环 k 次，读取所有的序偶
    for(int i=0; i<k; i++)
    {
        // 2. 对于读入的每一个序偶 <u, v>
        int u, v;
        scanf("%d %d", &u, &v);
        // 3. 将 relationMatrix[u - 1][v - 1] 的值置为 1
        relationMatrix[u-1][v-1] = 1;
    }

    /********** End **********/

    // 输出最终的 n x m 关系矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", relationMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
