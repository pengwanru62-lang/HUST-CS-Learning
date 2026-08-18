#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    /********* Begin *********/
    for(int i=2; i*i<=n; i++)
    {
        int cnt = 0;

        while(n % i == 0)
        {
            cnt++;
            n /= i;
        }

        if(cnt > 0)
        {
            cout << i << " " << cnt << endl;
        }
    }

    if(n > 1)
    {
        cout << n << " " << 1 << endl;
    }
    /********* End *********/
    
    return 0;
}