#include <stdio.h>
#include <math.h> // For pow function, or can use bit shift (1 << n)

int main() {
    // n: 集合 An 的大小
    int n;
    scanf("%d", &n);

    // set_A: 存储集合 An 的 n 个元素
    int set_A[12];
    for (int i = 0; i < n; i++) {
        scanf("%d", &set_A[i]);
    }

    /********** Begin **********/
    // 在此区域编写核心代码
    // 1. 循环 2 ^ n 次，每次循环代表 P(An) 的一个子集和 Bn 的一个 01 字符串。
    //    外层循环变量 i 从 0 到 2 ^ n - 1，i 的 n 位二进制表示就对应一个 01 字符串。
    // 2. 对于每一个 i, 输出对应的答案
/********** Begin **********/
// 1. 循环 2 ^ n 次
int total = 1 << n;  // 2^n 的简便写法（位运算）

for (int i = 0; i < total; i++) {
    // 2. 对于每一个 i，构造对应的子集和 01 字符串
    
    // 先输出子集部分
    printf("{");
    int first = 1;  // 标记是否是第一个元素，用于控制逗号
    
    for (int j = 0; j < n; j++) {
        if ((i >> (n - 1 - j)) & 1) {
            if (!first) {
                printf(",");
            }
            printf("%d", set_A[j]);
            first = 0;
        }
    }
    
    printf("}->");
    
    // 输出 01 字符串（从 b1 到 bn）
    for (int j = 0; j < n; j++) {
        // b1 对应最高位（第 n-1 位），b2 对应第 n-2 位，...
        if ((i >> (n - 1 - j)) & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
    
    printf("\n");
}
/********** End **********/


    return 0;
}
