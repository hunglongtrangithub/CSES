#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

void f(int k, int start, int middle, int end) {
    if (k == 1) cout << start << " " << end << endl;
    else {
        f(k - 1, start, end, middle);
        f(1, start, middle, end);
        f(k - 1, middle, start, end);
    }
}
int main() {
    int n;
    cin >> n;
    cout << int(pow(2, n)) - 1 << endl;
    f(n, 1, 2, 3);
}