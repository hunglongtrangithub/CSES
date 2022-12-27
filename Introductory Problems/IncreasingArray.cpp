#include <iostream>
using namespace std;
#define ll long long
int main() {
    ll n, p, a, ans=0;
    cin >> n;
    cin >> a;
    p=a;
    for (int i=1; i<n; ++i) {
        cin >> a;
        if (a<p) ans+=p-a;
        else p=a;
    }
    cout << ans;
}