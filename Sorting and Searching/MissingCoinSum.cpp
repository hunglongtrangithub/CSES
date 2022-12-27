#include <iostream>
#include <set>
#define ll long long

using namespace std;

int main() {
    ll n, x;
    multiset<ll> s;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }
    ll sum = 0;
    for (set<ll>::iterator it = s.begin(); it != s.end(); it++) {
        if (*it > sum + 1) {
            break;
        } else 
            sum += *it;
    }
    cout << sum + 1 << endl;
}