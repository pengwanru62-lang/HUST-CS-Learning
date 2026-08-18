#include <stdio.h>

int main() {
    // n: 集合 A 的大小
    int n;
    scanf("%d", &n);

    // matrix: 存储 n x n 的关系矩阵
    int matrix[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // isTransitive: 标记是否具有传递性，1 表示是，0 表示否。默认为是。
    int isTransitive = 1;

    /********** Begin **********/
    // 在此区域编写核心代码
    // 1. 使用三重循环遍历所有的 i, j, k 组合（i, j, k 从 0 到 n-1）
    // 2. 在循环中，检查是否存在 matrix[i][j] == 1 且 matrix[j][k] == 1，但 matrix[i][k] == 0 的情况
    // 3. 如果找到这样的三元组，说明关系不具有传递性。
    // 4. 此时，应将 isTransitive 标志位置为 0，并可以提前跳出所有循环，因为已经找到了反例。
    
    // 1. 使用三重循环遍历所有的 i, j, k 组合（i, j, k 从 0 到 n-1）
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                // 2. 在循环中，检查是否存在 matrix[i][j] == 1 且 matrix[j][k] == 1，但 matrix[i][k] == 0 的情况
                // 3. 如果找到这样的三元组，说明关系不具有传递性。
                if( matrix[i][j] == 1 && matrix[j][k] == 1 && matrix[i][k] == 0)
                {
                    // 4. 此时，应将 isTransitive 标志位置为 0，并可以提前跳出所有循环，因为已经找到了反例。
                    isTransitive = 0;
                    break;
                }
            }
        }
    }
    
    /********** End **********/

    // 根据 isTransitive 标志位的值输出最终结果
    if (isTransitive) {
        printf("Transitivity\n");
    } else {
        printf("None\n");
    }

    return 0;
}
