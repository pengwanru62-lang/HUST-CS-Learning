#include <stdio.h>

int main() {
    // n: 关系 f 中的序偶数量
    int n;
    scanf("%d", &n);

    // u, v: 分别存储 n 个序偶的第一个和第二个元素
    int u[100];
    int v[100];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &u[i], &v[i]);
    }

    // is_function: 标记关系是否为函数，1 表示是，0 表示否。默认为是。
    int is_function = 1;

    /********** Begin **********/
    // 在此区域编写核心代码
    // 1. 遍历所有已读入的序偶。
    // 2. 对于每个序偶 <u[i], v[i]>，需要检查是否存在另一个序偶 <u[j], v[j]>
    //    使得 u[i] == u[j] 但是 v[i] != v[j]。
    // 3. 这通常通过一个嵌套循环实现。外层循环遍历 i 从 0 到 n - 1。
    // 4. 内层循环遍历 j 从 i + 1 到 n - 1。
    // 5. 如果在循环中找到了满足上述条件的一对序偶，说明一个 x 对应了多个不同的 y。
    // 6. 此时，将 is_function 标志位置为 0，并可以立即跳出循环，因为已经确定不是函数。
    
    // 1. 遍历所有已读入的序偶。
    for(int i=0; i<n; i++)
    {
         // 2. 对于每个序偶 <u[i], v[i]>，需要检查是否存在另一个序偶 <u[j], v[j]>
         for(int j=i+1; j<n; j++)
         {
            //    使得 u[i] == u[j] 但是 v[i] != v[j]。
             if(u[i] == u[j] && v[i] != v[j])
             {
                 // 6. 此时，将 is_function 标志位置为 0，并可以立即跳出循环，因为已经确定不是函数。
                 is_function = 0;
                 break;
             }
         }
         if(!is_function)
         {
             break;
         }
    }  
    
    /********** End **********/

    // 根据 is_function 标志位的值输出最终结果
    if (is_function) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

