#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 M, e, n;
    cin >> M >> e >> n;

    // ===== begin: 请实现二进制模幂（快速幂），计算 C = M^e mod n =====
    // 要求：
    // 1) 使用 long long 保存中间变量（ans/base）
    // 2) 每次乘法后立刻取模，避免溢出和变大
    // 3) 处理 e == 0 的情况（结果应为 1）

    // ===== end: 请实现二进制模幂（快速幂），计算 C = M^e mod n =====
    long long result = 1;
    long long base = M % n;
    long long zhishu = e;

    while(zhishu > 0)
    {
        if(zhishu & 1)
        {
            result = (result * base) % n;
        }

        base = (base * base) % n;

        zhishu >>= 1;
    }

    cout << result << "\n";
    
    return 0;
}
