#include <iostream>
#include <set>
#define ll long long
using namespace std;

int main() {
    ll n, x;
    multiset<ll> s; // the set of coins
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }
    ll sum = 0; // the maximum sum of coins that can be made using a subset of the coins
    for (ll coin : s) {
        if (coin > sum + 1) {
            break;
        } else {
            sum += coin;
        }
    }
    cout << sum + 1 << endl; // the smallest number that cannot be made using a subset of the coins
}