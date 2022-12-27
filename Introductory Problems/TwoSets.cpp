#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
int main() {
    ll n;
    cin >> n;
    if (n%4==1 || n%4==2) cout << "NO";
    else {
        cout << "YES" << endl;
        ll k = (2+sqrt(4+8*(n*n+n)))/4;
        ll s = n*(n + 1)/4-(k+1+n)*(n-k)/2;
        cout << n-k+1 << endl;
        cout << s << " ";
        for (ll i=k+1; i<=n; ++i) cout << i << " ";
        cout << endl;
        cout << k-1 << endl;
        for (ll i=1; i<=k; ++i) {
            if (i != s) cout << i << " ";
        }
    }
}