#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

// 扩展欧几里得：求 gcd(a,b)，并找到 x,y 使得 a*x + b*y = gcd(a,b)
int64 exgcd(int64 a, int64 b, int64 &x, int64 &y) {
    // ===== begin: 请补全扩展欧几里得算法 =====
    // 目标：返回 gcd(a,b)，并通过引用参数 x,y 给出一组解
    // 提示：
    // 1) 递归边界：b == 0 时，gcd=a，x=1,y=0
    // 2) 递归展开：用子问题结果更新 x,y
    // ===== end: 请补全扩展欧几里得算法 =====
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int64 x1, y1;
    int64 gcd = exgcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b) * y1;
    return gcd;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 p, q, e;
    cin >> p >> q >> e;

    int64 phi = (p - 1) * (q - 1);

    // ===== begin: 请计算 d，使得 e*d ≡ 1 (mod phi) =====
    // 目标：
    // 1) 调用 exgcd(e, phi, x, y)，得到 x
    // 2) 因为 gcd(e,phi)=1，所以 x 就是 e 在模 phi 下的逆元（可能为负）
    // 3) 将 x 规范化到 [0, phi-1]（或题目要求的正范围）并输出
    // 提示：d = (x % phi + phi) % phi
    // ===== end: 请计算 d，使得 e*d ≡ 1 (mod phi) =====
    int64 x, y;
    exgcd(e, phi, x, y);
    int64 d = (x%phi + phi) % phi;
    cout << d << "\n";

    return 0;
}
