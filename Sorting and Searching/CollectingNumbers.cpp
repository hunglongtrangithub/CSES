#include <iostream>
#include <vector>
using namespace std;

int main() {
    long n, x;
    cin >> n;
    vector<long> v(n);
    for (long i = 0; i < n; i++) {
        cin >> x;
        v[x - 1] = i; // v[i - 1] = the index of the number i in the given array
    }
    long ans = 1;
    for (long i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}