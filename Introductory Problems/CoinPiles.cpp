#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        // if the sum of the piles is divisible by 3 and one pile cannot be more than twice the other pile
        string ans = ((a+b) % 3 == 0 && 2 * a >= b && 2 * b >= a) ? "YES" : "NO";
        cout << ans << endl;
    }
}