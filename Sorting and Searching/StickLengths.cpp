#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ll n, ans = 0;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if (n % 2 == 1) {
        ll median = (n - 1) / 2;
        for (ll i = 0; i < median; i++) 
            ans += v[i + median + 1] - v[i];
        cout << ans << endl;
    } else {
        for (ll i = 0; i < n / 2; i++)
            ans += v[i + n / 2] - v[i];
        cout << ans << endl;
    }
}