#include <iostream>
#include <vector>
#define ll long long
using namespace std;

// this algorithm works for convex polygons as well as concave polygons
int main() {
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    ll A = 0; // the value that is twice the actual area
    for (int i = 0; i < n-2; i++) {
        A += (x[i + 1] - x[0]) * (y[i + 2] - y[0]) - (x[i + 2] - x[0]) * (y[i + 1] - y[0]);
    }
    ll ans = (A > 0) ? A : -A;
    cout << ans << endl;
    return 0;
}
