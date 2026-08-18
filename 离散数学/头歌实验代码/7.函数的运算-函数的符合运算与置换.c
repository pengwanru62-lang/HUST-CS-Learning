#include <stdio.h>
#include <string.h> // For memcpy

int main() {
    // n: 集合 A = {1, 2, ..., n} 的大小
    int n;
    scanf("%d", &n);

    // f_map: 存储置换函数 f。f_map[i-1] = j 表示 f(i) = j
    int f_map[50];
    for (int i = 0; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        f_map[u - 1] = v;
    }

    // m: 复合的次数
    int m;
    scanf("%d", &m);

    // res_map: 存储最终复合 m 次后的置换结果
    int res_map[50];

    // temp_map: 用于在循环中存储临时的计算结果
    int temp_map[50];
    
    // 初始化 res_map 为恒等置换, res_map[i-1] = i
    for (int i = 0; i < n; i++) {
        res_map[i] = i + 1;
    }

    /********** Begin **********/
    // 在此区域编写核心代码
    // 1. 循环 m 次。
    // 2. 在每次循环中，计算一次复合：res_map = f o res_map
    //    a. 遍历 A 中的所有元素 i (从 0 到 n-1，代表数字 1 到 n)
    //    b. 当前 i + 1 经过 res_map 映射到 res_map[i]。
    //    c. 再将 res_map[i] 作为 f_map 的输入，得到 f(res_map[i])。
    //       由于 f_map 的下标是 0 - based，所以是 f_map[res_map[i] - 1]。
    //    d. 将这个结果存入临时数组 temp_map[i]。
    // 3. 一次复合计算完成后，将 temp_map 的内容复制回 res_map，为下一次复合做准备。

    // 1. 循环 m 次。
    for(int step=0; step<m; step++)
    {
         // 2. 在每次循环中，计算一次复合：res_map = f o res_map
        //  a. 遍历 A 中的所有元素 i (从 0 到 n-1，代表数字 1 到 n)
        for(int i=0; i<n; i++)
        {
            // c. 再将 res_map[i] 作为 f_map 的输入，得到 f(res_map[i])。
            // d. 将这个结果存入临时数组 temp_map[i]。
            temp_map[i] = f_map[res_map[i] - 1];
        }
        // 3. 一次复合计算完成后，将 temp_map 的内容复制回 res_map，为下一次复合做准备。
        for(int i=0; i<n; i++)
        {
            res_map[i] = temp_map[i];
        }
    } 
    /********** End **********/

    // 按格式输出最终 m 次置换后的结果
    for (int i = 0; i < n; i++) {
        printf("<%d,%d>\n", i + 1, res_map[i]);
    }

    return 0;
}
