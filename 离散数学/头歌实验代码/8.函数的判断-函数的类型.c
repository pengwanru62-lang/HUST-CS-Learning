#include <stdio.h>
#include <stdbool.h> // for bool type
#include <string.h>  // for memset

int main() {
    // sizeA: 集合 A 的大小, sizeB: 集合 B 的大小
    int sizeA, sizeB;
    scanf("%d %d", &sizeA, &sizeB);

    // n: 函数 f 中的序偶数量
    int n;
    scanf("%d", &n);

    // u, v: 分别存储 n 个序偶的第一个和第二个元素
    int u[100];
    int v[100];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &u[i], &v[i]);
    }

    // is_injective: 标记是否为单射
    // is_surjective: 标记是否为满射
    bool is_injective = true;
    bool is_surjective = true;

    /********** Begin **********/
    // 在此区域编写核心代码

    // 1. 首先，一个从 A 到 B 的函数必须为 A 中每一个元素都指定一个唯一的象。
    //    如果序偶数量不等于集合 A 的大小，它就不是一个从 A 到 B 的函数。
    //    因此，它既不是单射也不是满射。
    
    // 2. 检查单射 (Injective):
    //    遍历所有序偶，检查是否存在不同的 x 对应相同的 y。
    //    即，检查是否存在 i != j 使得 v[i] == v[j]。
    //    如果存在，则 is_injective = false;

    // 3. 检查满射 (Surjective):
    //    检查集合 B 中的每一个元素是否都是 A 中某个元素的象。
    //    可以创建一个大小为 sizeB + 1 的布尔数组 `mapb`，并初始化为 false。
    //    遍历所有序偶 <u, v>，将 `mapb[v]` 设为 true。
    //    最后，检查 `mapb` 数组从 1 到 sizeB，如果存在任何一个元素为 false，
    //    则 is_surjective = false;
    
    // 1. 首先，一个从 A 到 B 的函数必须为 A 中每一个元素都指定一个唯一的象。
    //    如果序偶数量不等于集合 A 的大小，它就不是一个从 A 到 B 的函数。
    //    因此，它既不是单射也不是满射。
    int a_up[101] = {0};
    bool mapb[101] = {false};

    for(int i=0; i<n; i++)  //扫描A中所有元素
    {
        a_up[u[i]]++;
    }

    for(int i=1; i<=sizeA; i++)
    {
        if(a_up[i] != 1)
        {
            is_injective = 0;
            is_surjective = 0;
            goto over;
        }
    }

    // 2. 检查单射 (Injective):
    //    遍历所有序偶，检查是否存在不同的 x 对应相同的 y。
    //    即，检查是否存在 i != j 使得 v[i] == v[j]。
    //    如果存在，则 is_injective = false;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(v[i]==v[j])
            {
                is_injective = false;
                break;
            }
        }
        if(!is_injective)
        {
            break;
        }
    }

    // 3. 检查满射 (Surjective):
    //    检查集合 B 中的每一个元素是否都是 A 中某个元素的象。
    //    可以创建一个大小为 sizeB + 1 的布尔数组 `mapb`，并初始化为 false。
    //    遍历所有序偶 <u, v>，将 `mapb[v]` 设为 true。
    //    最后，检查 `mapb` 数组从 1 到 sizeB，如果存在任何一个元素为 false，
    //    则 is_surjective = false;

    for(int i=0; i<n; i++)
    {
        mapb[v[i]] = true;
    }  
    
    for(int i=1; i<sizeB+1; i++)
    {
        if(mapb[i] == false)
        {
            is_surjective = false;
            break;
        }
    }

    over:
    /********** End **********/

    // 根据标志位输出最终结果
    if (is_injective && is_surjective) {
        printf("3\n"); // 双射
    } else if (is_injective) {
        printf("1\n"); // 仅单射
    } else if (is_surjective) {
        printf("2\n"); // 仅满射
    } else {
        printf("-1\n"); // 都不是
    }

    return 0;
}
