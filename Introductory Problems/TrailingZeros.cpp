#include <iostream>
using namespace std;

int main() {
    long n, ans = 0;
    cin >> n;
    while (n > 0) {
        n /= 5;
        ans += n;
    }
    cout << ans;
    return 0;
}
