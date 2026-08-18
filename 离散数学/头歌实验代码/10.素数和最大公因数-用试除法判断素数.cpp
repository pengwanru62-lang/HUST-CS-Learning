#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;

    bool is_prime = true;

    // ********** Begin ********** //
    if(n <= 1)
    {
        is_prime = false;
    }

    else if(n == 2)
    {
        is_prime = true;
    }

    else if(n % 2 == 0)
    {
        is_prime = false;
    }

    else
    {
        long long limit = sqrt(n);
        for(int i=3; i<=limit; i+=2)
        {
            if(n % i == 0)
            {
                is_prime = false;
                break;
            }
        }
    }

    // ********** End ********** //

    if (is_prime) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}