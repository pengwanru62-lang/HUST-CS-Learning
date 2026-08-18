#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

long long factorial(int n)
{
    long long res = 1;
    for(int i = 2; i <= n; i++)
        res *= i;
    return res;
}

int main() {
    string s;
    cin >> s;

    /********* Begin *********/

    map<char, int> cnt;

    for(char c : s)
        cnt[c]++;

    long long ans = factorial(s.length());

    for(auto p : cnt)
        ans /= factorial(p.second);

    cout << ans;

    /********* End *********/

    return 0;
}
