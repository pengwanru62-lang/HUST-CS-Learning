#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    /********* Begin *********/

    vector<int> pos(n, -1);
    long long sum = 0;

    for(int i = 0; i < n; i++) {
        sum += a[i];
        int r = sum % n;

        if(r == 0) {
            cout << i + 1 << endl;
            for(int j = 0; j <= i; j++) {
                cout << a[j];
                if(j < i) cout << " ";
            }
            cout << endl;
            return 0;
        }

        if(pos[r] != -1) {
            int l = pos[r] + 1;
            int len = i - pos[r];

            cout << len << endl;
            for(int j = l; j <= i; j++) {
                cout << a[j];
                if(j < i) cout << " ";
            }
            cout << endl;
            return 0;
        }

        pos[r] = i;
    }

    /********* End *********/

    return 0;
}
