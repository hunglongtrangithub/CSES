#include <iostream>
#include <cmath>
using namespace std;

void f(long k, long start, long middle, long end) {
    if (k == 1) {
        cout << start << " " << end << endl;
    } else {
        f(k - 1, start, end, middle);
        f(1, start, middle, end);
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