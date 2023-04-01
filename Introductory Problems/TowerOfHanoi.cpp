#include <iostream>
#include <cmath>
using namespace std;

void f(long k, long start, long middle, long end) {
    if (k == 1) {
        cout << start << " " << end << endl;
    } else {
        // Move k - 1 disks from start to middle.
        f(k - 1, start, end, middle);
        // Move the last disk from start to end.
        f(1, start, middle, end);
        // Move k - 1 disks from middle to end.
        f(k - 1, middle, start, end);
    }
}

int main() {
    long n;
    cin >> n;
    cout << long(pow(2, n)) - 1 << endl;
    f(n, 1, 2, 3);
    return 0;
}