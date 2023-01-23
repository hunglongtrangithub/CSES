#include <iostream>
using namespace std;

int main() {
    long t;
    cin >> t;
    while (t--) {
        long y, x;
        cin >> y >> x;
        long k = max(x, y);
        long pivot = k * k - k + 1;
        if (k % 2 == 0) {
            cout << pivot - x + y << endl;
        } else {
            cout << pivot + x - y << endl;
        }
    }
    return 0;
}