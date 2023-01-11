#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;
    for (int k = 1; k <= n; k++) 
        cout << (k * k) * (k * k - 1) / 2 - 4 * (k - 1) * (k - 2) << endl;
}
