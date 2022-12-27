#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll x = 0, y = 0, ans = 0;
    while (x < n && y < m) {
        if (b[y] > a[x] + k)
            x++;
        else if (b[y] < a[x] - k)
            y++;
        else {
            ans++;
            x++;
            y++;
        }
    }
    cout << ans << endl;
}