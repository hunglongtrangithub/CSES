#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long n, ans = 0;
    cin >> n;
    vector<long> v(n);
    for (long i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    // the mininum total cost is when along the sticks are the same length as the median stick
    if (n % 2 == 1) {
        long median = (n - 1) / 2;
        for (long i = 0; i < median; i++) {
            ans += v[i + median + 1] - v[i];
        } 
        cout << ans;
    } else {
        for (long i = 0; i < n / 2; i++) {
            ans += v[i + n / 2] - v[i];
        }
        cout << ans;
    }
    return 0;
}