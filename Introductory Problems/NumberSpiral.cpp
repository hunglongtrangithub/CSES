#include <iostream>
using namespace std;

int main() {
    long t;
    cin >> t;
    while (t--) {
        long y, x;
        cin >> y >> x;
        long k = max(x, y);
        // pivot is the number at the bottom right corner of the square with side length k
        long pivot = k * k - k + 1; // derived from pivot(k + 1) = pivot(k) + 2k (pivot(1) = 1)
        if (k % 2 == 0) {
            cout << pivot - x + y << endl;
        } else {
            cout << pivot + x - y << endl;
        }
    }
    return 0;
}