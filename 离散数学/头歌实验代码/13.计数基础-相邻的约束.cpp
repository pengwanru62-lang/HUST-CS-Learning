#include <iostream>
#include <vector>
#include <stdio.h>

#define MOD 1000000007
using namespace std;

int main() {
    int n, k;
    
    cin >> n;
    cin >> k;


    /********* Begin *********/
    int bad[10][10] = {0};

    //记录不吉利数字对
    for(int i=0; i<k; i++)
    {
        int u, v;
        scanf("%d %d",&u, &v);
        bad[u][v] = 1;
    }

    //初始化dp数组
    long long dp[1001][10] = {0};

    for(int j=0; j<10; j++)
    {
        dp[1][j] = 1;
    }

    //开始动态规划
    for(int i=2; i<=n; i++)//扫描长度
    {
        for(int last = 0; last<10; last++)//扫描末尾字符
        {
            for(int pre=0; pre<10; pre++)
            {
                if(!bad[pre][last])
                {
                    dp[i][last] = (dp[i][last] + dp[i-1][pre]) % MOD;
                }
            }
        }
    }

    //计算累加结果
    long long ans = 0;
    for(int j=0; j<10; j++)//扫描末尾字符
    {
        ans = (ans + dp[n][j]) % MOD;
    }

    printf("%lld\n", ans);
    /********* End *********/

    return 0;
}