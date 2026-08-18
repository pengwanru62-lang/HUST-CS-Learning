#include <stdio.h>

int main() {
    // 变量 n 代表数值范围 1~n
    // 变量 m 代表质数的个数
    long long n;
    int m;
    scanf("%lld %d", &n, &m);

    // 数组 primes 用来存储 m 个质数
    int primes[15];
    for (int i = 0; i < m; i++) {
        scanf("%d", &primes[i]);
    }

    // 变量 result 用于存储最终结果
    long long result = 0;

    /********** Begin **********/
    // 在此区域编写核心代码
    // 1. 遍历 m 个质数的所有非空子集
    // 2. 对于每一个子集：
    //    a. 计算子集中所有质数的乘积
    //    b. 根据子集中元素的个数（奇数或偶数）
    //    c. 对 n / 乘积 的结果进行加或减运算，累加到 result 中
    
    //1.遍历m个质数的所有非空子集
    for(int mask = 1; mask < (1<<m); mask++)   //排除空集
    {
        long long pro = 1;  //累计当前质数的乘积之和
        int cnt = 0;        //计算一共有多少个元素

        //遍历primes数组的每一位，判断该质数元素是否在当前子集之中
        for(int i=0; i<m; i++)
        {
            if(mask & (1<<i))   //判断第i位是否被选中
            {
                cnt++;
                pro *= primes[i];
            }
        }

        //判断是否溢出
        if(pro > n) continue;   //溢出时候结束本次循环

        //计算符号
        if(cnt % 2 == 0)
        {
            result -= n/pro;
        }
        else
        {
            result += n/pro;
        }
    }
    /********** End **********/

    // 输出最终结果
    printf("%lld\n", result);

    return 0;
}
