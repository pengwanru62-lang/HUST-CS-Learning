#include <iostream>

using namespace std;

int main() {
    long long a, n, m;

    if (!(cin >> a >> n >> m)) {
        return 0;
    }

    long long ans;

    // ********** Begin ********** //
    //如果初始指数 n=0，循环不执行，ans 保持为 1,所以这里需要初始化
    ans = 1 % m;
    // 将底数 base 初始化为 a % m
    long long base = (a % m + m) % m;
    //当指数 n > 0 时，循环执行
    while(n>0)
    {
        if(n&1)
        {
            ans = (ans * base) % m;
        }
        base = (base * base) % m;
        n = n>>1;
    }

    // ********** End ********** //

    cout << ans << endl;

    return 0;
}