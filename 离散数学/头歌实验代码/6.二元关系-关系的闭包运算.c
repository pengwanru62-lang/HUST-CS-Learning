#include <stdio.h>

int main() {
    // n: 集合 A 的大小
    int n;
    scanf("%d", &n);

    // matrix: 存储 n x n 的关系矩阵，将在此矩阵上直接计算传递闭包
    int matrix[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    /********** Begin **********/
    // 在此区域使用 Warshall 算法实现传递闭包的计算
    // 1. 使用三重循环，k 作为中间点，从 0 到 n - 1 遍历
    // 2. 内层 i 和 j 循环，遍历矩阵的所有元素
    // 3. 应用 Warshall 算法的核心思想：
    //    如果存在从 i 到 k 的路径 (matrix[i][k] == 1) 
    //    并且存在从 k 到 j 的路径 (matrix[k][j] == 1),
    //    那么就一定存在从 i 到 j 的路径。
    // 4. 更新 matrix[i][j] 的值: 
    //    matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);
    
    // 1. 使用三重循环，k 作为中间点，从 0 到 n - 1 遍历
    for(int k=0; k<n; k++)  //k在最外层相当于轮数，分别计算W1~Wk
    {
        // 2. 内层 i 和 j 循环，遍历矩阵的所有元素
        // 3. 应用 Warshall 算法的核心思想：
        //    如果存在从 i 到 k 的路径 (matrix[i][k] == 1) 
        //    并且存在从 k 到 j 的路径 (matrix[k][j] == 1),
        //    那么就一定存在从 i 到 j 的路径。
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                // 4. 更新 matrix[i][j] 的值:
                matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);
            }
        }
    } 
    /********** End **********/

    // 输出计算得到的 n x n 传递闭包矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
