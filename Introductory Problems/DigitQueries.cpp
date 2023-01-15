#include <iostream>
#include <vector>
#include <utility>
#define ll long long 
using namespace std;

string digit;
vector<pair<ll, ll> > pivot(19, make_pair(1, 1)); // pivot[i] = (sum of digits in numbers with i digits, 10^i)

int main() {
    // precompute the pivots
    for (int n = 1; n < 19; n++) {
        pivot[n].first = pivot[n - 1].first + 9 * pivot[n - 1].second * n;
        pivot[n].second = pivot[n - 1].second * 10;
    }
    ll q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        int i = 1;
        // find the pivots that k is in between
         while (pivot[i - 1].first > k || k >= pivot[i].first) {
            i++;
        }
        k = k - pivot[i - 1].first + 1;
        ll num = pivot[i - 1].second + k / i;
        if (k % i) {
            digit = to_string(num)[k % i - 1];
        } else {
            digit = to_string(num - 1)[to_string(num - 1).size() - 1];
        }
        cout << digit << endl;
    }
}