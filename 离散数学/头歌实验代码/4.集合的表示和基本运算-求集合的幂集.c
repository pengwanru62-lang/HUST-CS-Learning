/*
鉴于此题代码难度较高，实现不易。
已经给出此题的完整做法，请仔细阅读并学习。
*/

#include <stdio.h>

int main() {
    // 变量 n 用来存储集合 A 的大小
    int n;
    scanf("%d", &n);

    // 数组 setA 用来存储集合 A 的元素
    int setA[25];
    for (int i = 0; i < n; i++) {
        scanf("%d", &setA[i]);
    }

    // 根据要求，首先输出空集
    printf("emptyset\n");

    /********** Begin **********/
    // 在此区域编写核心代码
    // 1. 按照字典序遍历所有可能的集合
    // 2. 按照题目要求格式输出

    for (int k = 1; k <= n; k++) {
        int p[25]; // p数组用于记录当前组合中元素在setA中的下标
        
        // 1. 初始化当前大小为 k 的第一个组合，即最小下标 0, 1, 2... k - 1
        for (int i = 0; i < k; i++) {
            p[i] = i;
        }
        
        while (1) {
            // 2. 按照题目要求格式输出当前组合
            printf("{");
            for (int i = 0; i < k; i++) {
                printf("%d", setA[p[i]]);
                if (i < k - 1) {
                    printf(",");
                }
            }
            printf("}\n");
            
            // 3. 寻找下一个字典序的组合
            int j = k - 1;
            while (j >= 0 && p[j] == n - k + j) {
                j--;
            }
            
            if (j < 0) {
                break;
            }
            
            p[j]++;
            
            for (int m = j + 1; m < k; m++) {
                p[m] = p[m - 1] + 1;
            }
        }
    }

    /********** End **********/

    return 0;
}