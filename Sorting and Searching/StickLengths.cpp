#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ll n, ans = 0;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    // the mininum total cost is when all the sticks are the same length as the median stick
    if (n % 2 == 1) {
        ll median = (n - 1) / 2;
        for (int i = 0; i < median; i++) {
            ans += v[i + median + 1] - v[i];
        } 
        cout << ans << endl;
    } else {
        for (int i = 0; i < n / 2; i++) {
            ans += v[i + n / 2] - v[i];
        }
        cout << ans << endl;
    }
}