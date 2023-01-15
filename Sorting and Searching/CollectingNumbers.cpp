#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll n, x;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        v[x - 1] = i; // v[i - 1] = the index of the number i in the given array
    }
    ll ans = 1;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            ans++;
        }
    }
    cout << ans << endl;
}