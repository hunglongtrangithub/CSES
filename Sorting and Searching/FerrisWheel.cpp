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
    ll i = 0, j = n - 1, ans = 0; // ans: number of pairs of children who can ride 1 gondola
    while (i < j) {
        if (v[i] + v[j] > x) {
            j--;
        }
        else {
            // increase the number of pairs by 1 and find the next pair
            ans++;
            i++;
            j--;
        }
    }
    cout << n - ans << endl;
}