#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
int main() {
    int n, ans=0;
    cin >> n;
    while (n>0) {
        n /= 5;
        ans += n;
    }
    cout << ans;
}
