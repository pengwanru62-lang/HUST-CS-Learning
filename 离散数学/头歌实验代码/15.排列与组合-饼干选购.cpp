#include <iostream>

using namespace std;

// 计算组合数 C(n,k)
long long C(int n, int k)
{
    if(k > n) return 0;
    if(k > n - k) k = n - k;

    long long ans = 1;
    for(int i = 1; i <= k; i++)
    {
        ans = ans * (n - k + i) / i;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    /********* Begin *********/

    cout << C(n + k - 1, k);

    /********* End *********/

    return 0;
}
