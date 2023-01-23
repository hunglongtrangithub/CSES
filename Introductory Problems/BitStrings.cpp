#include <iostream>
using namespace std;

int main() {
    long n, s = 1;
    cin >> n;
    // s = 2^n
    for (long i = 0; i < n; i++) {
        s = (2 * s) % long(1e9 + 7);
    }
    cout << s;
    return 0;
}
