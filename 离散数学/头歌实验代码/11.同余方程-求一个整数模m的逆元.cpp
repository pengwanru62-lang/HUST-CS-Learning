#include <iostream>

using namespace std;

long long exgcd(long long a, long long b, long long &x, long long &y) {
    /********* Begin *********/
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long d = exgcd(b, a%b, x1, y1);

    x = y1;
    y = x1 - (a/b) * y1;

    return d;
    /********* End *********/
}

long long modInverse(long long a, long long m) {
    /********* Begin *********/
    long long x, y;
    long long d = exgcd(a, m, x, y);

    return (x % m + m) % m;

    /********* End *********/
}

int main() {
    long long a, m;
    if (cin >> a >> m) {
        cout << modInverse(a, m) << endl;
    }
    return 0;
}