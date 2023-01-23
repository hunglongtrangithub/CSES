#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll n, p = INT32_MIN, element, ans = 0;
    cin >> n;
    for (long i = 0; i < n; i++) {
        cin >> element;
        if (element < p) {
            ans += p - element;
        } else { 
            p = element;
        }
    }
    cout << ans;
    return 0;
}