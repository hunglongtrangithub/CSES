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
    multiset<ll> check;
    check.insert(v[0]);
    for (ll i : v) {
        multiset<ll>::iterator it = check.upper_bound(i);
        if (it != check.end()) {
            check.erase(it);
        }
        check.insert(i);
    }
    cout << check.size() << endl;
}