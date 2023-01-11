#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll n, t;
    cin >> n >> t;
    vector<ll> machines(n); 
    for (ll i = 0; i < n; i++) {
        cin >> machines[i];
    }
    // binary search 
    ll left = 0, right = 1e18;
    while (left < right) {
        ll mid = (left + right) / 2;
        ll max_product = 0; // max number of items produced in time mid
        for (int i = 0; i < n; i++) {
            max_product += min(mid / machines[i], (ll)1e9);
        }
        if (max_product >= t) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;
}