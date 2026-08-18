#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;
const long long INV4 = 250000002; // 4在MOD下的逆元

long long qpow(long long a, long long b)
{
    long long res = 1;
    while(b)
    {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    /********* Begin *********/

    long long p = qpow(3, n);

    long long term;
    if(n % 2 == 0)
        term = 1;          // (-1)^n = 1
    else
        term = MOD - 1;    // (-1)^n = -1

    long long ans = (p - term + MOD) % MOD;
    ans = ans * INV4 % MOD;

    cout << ans;

    /********* End *********/

    return 0;
}
