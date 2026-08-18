#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    long long m;

    if (!(cin >> a >> b >> m)) {
        return 0;
    }

    // ********** Begin ********** //
    int remainder_a = 0;
    int remainder_b = 0;

    // 原理：X = d₁×10^(n-1) + d₂×10^(n-2) + ... + dₙ×10⁰
    for(char digit : a)
    {
        remainder_a = (remainder_a * 10 + (digit - '0')) % m;
    }

    for(char digit : b)
    {
        remainder_b = (remainder_b * 10 + (digit - '0')) % m;
    }

    if(remainder_a == remainder_b)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    // ********** End ********** //

    return 0;
}