#include <iostream>
#include <vector>
using namespace std;

// this algorithm works for convex polygons as well as concave polygons
int main() {
    long n;
    cin >> n;
    vector<long> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    long A = 0; // the value that is twice the actual area
    for (int i = 0; i < n - 2; i++) {
        A += (x[i + 1] - x[0]) * (y[i + 2] - y[0]) - (x[i + 2] - x[0]) * (y[i + 1] - y[0]);
    }
    long ans = (A > 0) ? A : -A;
    cout << ans;
    return 0;
}
