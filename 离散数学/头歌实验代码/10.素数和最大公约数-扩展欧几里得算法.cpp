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
    y = x1 - (a/b)*y1;

    return d;
    /********* End *********/
}

int main() {
    long long a, b;
    long long x, y;
    if (cin >> a >> b) {
        long long d = exgcd(a, b, x, y);
        cout << x << " " << y << " " << d << endl;
    }
    return 0;
}