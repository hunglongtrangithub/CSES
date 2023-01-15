#include <iostream>
#include <set>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    set<ll> s;
    ll i = 0, j = 0, ans = 0;
    while (i < n && j < n) {
        while (j < n && s.count(v[j]) == 0) {
            s.insert(v[j]);
            j++;
        }
        if (j - i > ans) {
            ans = j - i;
        }
        while (i < n && v[i] != v[j]) {
            s.erase(v[i]);
            i++;
        }
        i++;
        j++;
    }
    cout << ans << endl;
}