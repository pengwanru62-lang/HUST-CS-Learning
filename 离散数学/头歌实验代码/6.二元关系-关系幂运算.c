#include <stdio.h>
#include <string.h>

int main() {
    // n: 集合 A 的大小, m: 幂次
    int n, m;
    scanf("%d %d", &n, &m);

    // R: 存储 n x n 的关系矩阵
    int R[50][50];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &R[i][j]);
        }
    }

    // result: 存储最终的 n x n 关系矩阵 R^m
    int result[50][50];
    // temp: 用于在矩阵乘法中存储中间结果
    int temp[50][50];

    /********** Begin **********/
    // 在此区域编写核心代码
    // 1. 考虑 m = 0 的情况
    // 2. 进行矩阵乘法
    
    // 1. 考虑 m = 0 的情况
    if(m == 0)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                result[i][j] = (i==j) ? 1 : 0;
            }
        }
    }
    else
    {
        //初始化result矩阵，对应R
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                result[i][j] = R[i][j];
            }
        }

        // 2. 进行矩阵乘法
        for(int r=1; r<m; r++)  //进行m-1次循环
        {
            for(int i=0; i<n; i++)  //控制行
            {
                for(int j=0; j<n; j++)  //控制列
                {
                    temp[i][j] = 0; //temp初始化
                    for(int k=0; k<n; k++)
                    {
                        if(result[i][k] && R[k][j])
                        {
                            temp[i][j] = 1; //一定要用temp存放，否则原本应参与下一轮计算的更新的result参与了本轮计算
                            break;
                        }
                    }
                }
            }
            //每一轮更新一次result矩阵
            for(int i=0; i<n; i++)
            {
                for(int j = 0; j<n; j++)
                {
                    result[i][j] = temp[i][j];
                }
            }
            
        }
    }     
    /********** End **********/

    // 输出最终的 n x n 结果矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
