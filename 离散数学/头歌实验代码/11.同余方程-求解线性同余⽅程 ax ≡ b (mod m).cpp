#include <iostream>

using namespace std;

long long exgcd(long long a, long long b, long long &x, long long &y) {
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
}

long long modInverse(long long a, long long m) {
    long long x, y;
    exgcd(a, m, x, y);
    return (x % m + m) % m;
}

int main() {
    long long a, b, m;
    cin >> a >> b >> m;

    /********* Begin *********/
    long long inv = modInverse(a,m);

    long long x = (inv*b)%m;

    cout << x << endl;

    /********* End *********/

    return 0;
}