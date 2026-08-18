#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    /********* Begin *********/

    vector<int> pos(4, -1);

    for(int i = 0; i < n; i++) {
        int x = abs(points[i].first) % 2;
        int y = abs(points[i].second) % 2;

        int id = x * 2 + y;

        if(pos[id] != -1) {
            cout << points[pos[id]].first << " "
                 << points[pos[id]].second << endl;
            cout << points[i].first << " "
                 << points[i].second << endl;
            return 0;
        }

        pos[id] = i;
    }

    /********* End *********/

    return 0;
}
