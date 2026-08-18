#include <stdio.h>
#include <stdlib.h> // for qsort

// 比较函数，用于 qsort 升序排序
int comp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    // n: 集合 A 的大小
    int n;
    scanf("%d", &n);

    // rel_mat: 存储 n x n 的偏序关系矩阵
    int rel_mat[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &rel_mat[i][j]);
        }
    }

    // k: 子集 B 的大小
    int k;
    scanf("%d", &k);

    // sub_b: 存储子集 B 的 k 个元素
    int sub_b[100];
    for (int i = 0; i < k; i++) {
        scanf("%d", &sub_b[i]);
    }
    
    // 存储结果的数组
    int great_e[100], least_e[100];
    int max_e[100], min_e[100];
    int g_cnt = 0, l_cnt = 0, max_cnt = 0, min_cnt = 0;


    /********** Begin **********/
    // 在此区域编写核心代码
    // 提示: 矩阵 rel_mat[i][j] == 1 表示 (i + 1) <= (j + 1)
    
    // 1. 找出极大元:
    //    遍历子集 sub_b 中的每个元素 b。
    //    对于每个 b, 再次遍历 sub_b 中所有元素 x。
    //    如果找不到任何一个 x 使得 b < x (即 rel_mat[b - 1][x - 1] == 1 且 b != x),
    //    那么 b就是一个极大元, 将其存入 max_e 数组。

    // 2. 找出极小元:
    //    遍历子集 sub_b 中的每个元素 b。
    //    对于每个 b, 再次遍历 sub_b 中所有元素 x。
    //    如果找不到任何一个 x 使得 x < b (即 rel_mat[x - 1][b - 1] == 1 且 x != b),
    //    那么 b 就是一个极小元, 将其存入 min_e 数组。

    // 3. 找出最大元:
    //    最大元一定是唯一的极大元。
    //    如果极大元只有一个, 检查它是否大于等于 B 中所有元素。
    //    如果都满足，则是最大元。

    // 4. 找出最小元:
    //    最小元一定是唯一的极小元。
    //    如果极小元只有一个, 检查它是否小于等于 B 中所有元素。
    //    如果都满足，则是最小元。

    // 5. 对四个结果数组分别进行升序排序。
    //    qsort(great_e, g_cnt, sizeof(int), comp);
    //    ... (以此类推)
    
    // 1. 找出极大元:
    //    遍历子集 sub_b 中的每个元素 b。
    for(int i=1; i<=k; i++)
    {   
        int is_found = 1;
        int b = sub_b[i-1];
        //    对于每个 b, 再次遍历 sub_b 中所有元素 x。
        for(int j=1; j<=k; j++)
        {
            int x = sub_b[j-1];
            //    如果找不到任何一个 x 使得 b < x (即 rel_mat[b - 1][x - 1] == 1 且 b != x),
            if(rel_mat[b-1][x-1]==1 && b!=x)
            {
                is_found = 0;
            }
        }
        //    那么 b就是一个极大元, 将其存入 max_e 数组。
        if(is_found)
        {
            max_e[max_cnt++] = b;
        }
    }

    // 2. 找出极小元:
    //    遍历子集 sub_b 中的每个元素 b。
    for(int i = 1; i<=k; i++)
    {
        int is_found = 1;
        int b = sub_b[i-1];
        //    对于每个 b, 再次遍历 sub_b 中所有元素 x。
        for(int j = 1; j<=k; j++)
        {
            int x = sub_b[j-1];
            //    如果找不到任何一个 x 使得 x < b (即 rel_mat[x - 1][b - 1] == 1 且 x != b),
            if(rel_mat[x - 1][b - 1] == 1 && x != b)
            {
                is_found = 0;
            }
        }
        //    那么 b 就是一个极小元, 将其存入 min_e 数组。
        if(is_found)
        {
            min_e[min_cnt++] = b;
        }
    }

    // 3. 找出最大元:
    //    最大元一定是唯一的极大元。
    //    如果极大元只有一个, 检查它是否大于等于 B 中所有元素。
    if(max_cnt == 1)
    {
        int max = max_e[0];
        int is_max = 1;
        for(int i = 0; i<k; i++)
        {
            int x = sub_b[i];
            if(rel_mat[max][x] == 1 && x!=max)
            {
                is_max = 0;
            }
        }
        //    如果都满足，则是最大元。
        if(is_max == 1)
        {
            great_e[g_cnt++] = max;
        }
    }

    // 4. 找出最小元:
    //    最小元一定是唯一的极小元。
    //    如果极小元只有一个, 检查它是否小于等于 B 中所有元素。
    if(min_cnt == 1)
    {
        int min = min_e[0];
        int is_min = 1;
        for(int i = 0; i<k; i++)
        {
            int x = sub_b[i];
            if(rel_mat[x][min] == 1 && x != min)
            {
                is_min = 0;
            }
        }
        //    如果都满足，则是最小元。
        if(is_min)
        {
            least_e[l_cnt++] = min;
        }
    }

    // 5. 对四个结果数组分别进行升序排序。
    //    qsort(great_e, g_cnt, sizeof(int), comp);
    qsort(great_e, g_cnt, sizeof(int), comp);
    qsort(min_e, min_cnt, sizeof(int), comp);
    qsort(max_e, max_cnt, sizeof(int), comp);
    qsort(least_e, l_cnt, sizeof(int), comp);

    /********** End **********/

    // 输出最大元
    for (int i = 0; i < g_cnt; i++) printf("%d%c", great_e[i], i == g_cnt - 1 ? '\n' : ' ');
    if (g_cnt == 0) printf("\n");
    
    // 输出最小元
    for (int i = 0; i < l_cnt; i++) printf("%d%c", least_e[i], i == l_cnt - 1 ? '\n' : ' ');
    if (l_cnt == 0) printf("\n");

    // 输出极大元
    for (int i = 0; i < max_cnt; i++) printf("%d%c", max_e[i], i == max_cnt - 1 ? '\n' : ' ');
    if (max_cnt == 0) printf("\n");

    // 输出极小元
    for (int i = 0; i < min_cnt; i++) printf("%d%c", min_e[i], i == min_cnt - 1 ? '\n' : ' ');
    if (min_cnt == 0) printf("\n");

    return 0;
}
