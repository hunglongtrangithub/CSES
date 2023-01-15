#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll n, t;
    cin >> n >> t;
    vector<ll> machines(n); 
    for (int i = 0; i < n; i++) {
        cin >> machines[i];
    }
    /* We have an array of the maximum number of items produced max_product according to the given time as the index 
    (time ranges from 0 to 10^18). Because max_product increases with time, we can use binary search to find 
    the minimum time required to produce t items by finding the smallest index where its max_product >= t. */ 
    ll left = 0, right = 1e18; 
    while (left < right) {
        ll mid = (left + right) / 2;
        ll max_product = 0; // max number of items produced in time mid
        /* The upper bound for max_product is (2 * 10^5) * (10^18 / 1) = 2 * 10^23, which is larger than 
        the maximum value of ll (2^63 - 1). So we need to prevent overflow by stopping adding up max_product 
        when it is already >= t. */
        for (int i = 0; i < n; i++) {
            max_product += mid / machines[i];
            if (max_product >= t) {
                break; // no need to continue if max_product is already >= t
            }
        }
        if (max_product >= t) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;
}