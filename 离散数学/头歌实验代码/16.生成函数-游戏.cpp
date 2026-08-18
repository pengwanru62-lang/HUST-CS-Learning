#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a_stones(n);
    for(int i = 0; i < n; i++) {
        cin >> a_stones[i];
    }

    int m;
    cin >> m;
    vector<int> b_stones(m);
    for(int i = 0; i < m; i++) {
        cin >> b_stones[i];
    }

    /********* Begin *********/

    vector<long long> a(501, 0);
    vector<long long> b(501, 0);

    for(int x : a_stones) a[x]++;
    for(int x : b_stones) b[x]++;

    vector<long long> c(1001, 0);

    for(int i = 0; i <= 500; i++) {
        if(a[i] == 0) continue;

        for(int j = 0; j <= 500; j++) {
            if(b[j] == 0) continue;

            c[i + j] += a[i] * b[j];
        }
    }

    for(int s = 0; s <= 1000; s++) {
        if(c[s] > 0) {
            cout << s << " " << c[s] << endl;
        }
    }

    /********* End *********/

    return 0;
}
