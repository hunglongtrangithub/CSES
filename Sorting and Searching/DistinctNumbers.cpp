#include <set>
#include <iostream>
#define ll long long

using namespace std;

int main() {
    ll n;
    cin >> n;
    ll x;
    set<ll> s;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;
}