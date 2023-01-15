#include <iostream>
#include <set>
#define ll long long
using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;
    multiset<ll> s;
    for (int i = 0; i < n; i++) {
        ll h;
        cin >> h;
        s.insert(h);
    }
    for (int i = 0; i < m; i++) {
        ll t;
        cin >> t;
        multiset<ll>::iterator it = s.upper_bound(t);
        if (it == s.begin()) {
            cout << -1 << endl;
        }
        else {
            it--;
            cout << *it << endl;
            s.erase(it);
        }
    }
}