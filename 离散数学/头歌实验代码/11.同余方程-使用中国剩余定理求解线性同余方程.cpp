#include <iostream>
#include <vector>

using namespace std;

long long exgcd(long long a, long long b, long long &x, long long &y) {
    /********* Begin *********/
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
    /********* End *********/
}

long long solveCRT(int n, const vector<long long>& a, const vector<long long>& m) {
    /********* Begin *********/
    //计算所有模数的乘积M
    long long M = 1;
    for(int i=0;i<n;i++)
    {
        M*=m[i];
    }

    long long result = 0;

    //求解每个方程
    for(int i = 0; i<n; i++)
    {
        long long Mi = M/m[i];

        long long ti, y;
        exgcd(Mi, m[i], ti, y);
        ti = (ti % m[i] + m[i]) % m[i];

        result += a[i]*Mi*ti;
    }

    result = (result % M + M) % M;
    return result;
    /********* End *********/
}

int main() {
    int n;
    if (cin >> n) {
        vector<long long> a(n), m(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> m[i];
        }
        cout << solveCRT(n, a, m) << endl;
    }
    return 0;
}