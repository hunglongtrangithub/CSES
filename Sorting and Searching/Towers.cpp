#include <iostream>
#include <set>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    multiset<ll> check;
    check.insert(v[0]);
    for (int i = 1; i < n; i++) {
        multiset<ll>::iterator it = check.upper_bound(v[i]);
        if (it != check.end()) 
            check.erase(it);
        check.insert(v[i]);
    }
    cout << check.size() << endl;
}