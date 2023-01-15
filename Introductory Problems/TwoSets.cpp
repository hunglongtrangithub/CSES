#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
int main() {
    ll n;
    cin >> n;
    if (n % 4 == 1 || n % 4 == 2) {
        cout << "NO";
    } else {
        cout << "YES" << endl;
        ll k = (1 + sqrt(1 + 2 * (n * (n + 1)))) / 2; // k is the number of elements in the first set
        ll s = n * (n + 1) / 4 - (k + 1 + n) * (n - k) / 2; // (1 <= s <= k)
        // the first set consists of s and consecutive numbers from k + 1 to n 
        cout << n - k + 1 << endl;
        cout << s << " ";
        for (ll i = k + 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << endl;
        cout << k - 1 << endl;
        // the second set consists of consecutive numbers from 1 to k except for s
        for (ll i = 1; i <= k; i++) {
            if (i != s) {
                cout << i << " ";
            }
        }
    }
}