#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll i = 0, j = n - 1, ans = 0;
    while (i < j) {
        if (v[i] + v[j] > x) 
            j--;
        else {
            ans++;
            i++;
            j--;
        }
    }
    cout << n - ans << endl;
}