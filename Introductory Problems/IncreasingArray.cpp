#include <iostream>
using namespace std;

int main() {
    long n, p = INT64_MIN, element, ans = 0;
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