#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll y, x;
        cin >> y >> x;
        ll k = max(x, y);
        ll pivot = k * k - k + 1;
        if (k % 2 == 0) cout << pivot - x + y << endl;
        else cout << pivot + x - y << endl;
    }
}