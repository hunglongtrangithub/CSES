#include <set>
#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll x;
    set<ll> s;
    while (n--) {
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;
}