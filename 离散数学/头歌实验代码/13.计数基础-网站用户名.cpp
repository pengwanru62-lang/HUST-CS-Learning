#include <iostream>
#include <cmath>

using namespace std;

long long calculateTotalUsernames() {
    /********* Begin *********/
    long long power_rule1 = pow(26, 4);
    long long power_rule2 = 26 * 10 * 10;
    return power_rule1 + power_rule2;

    /********* End *********/
}

int main() {
    cout << calculateTotalUsernames() << endl;
    return 0;
}