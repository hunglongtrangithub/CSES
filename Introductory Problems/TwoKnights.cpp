#include <iostream>
using namespace std;

int main() {
    long n;
    cin >> n;
    for (long k = 1; k <= n; k++) {
        long ans = ((k * k) * ((k * k) - 1)) / 2 - 4 * (k - 1) * (k - 2);
        cout << ans << endl;
    }
    return 0;
}
