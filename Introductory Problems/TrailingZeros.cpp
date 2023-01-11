#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    while (n > 0) {
        n /= 5;
        ans += n;
    }
    cout << ans;
}
