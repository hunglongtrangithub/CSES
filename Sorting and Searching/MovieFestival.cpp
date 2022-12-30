#include <iostream>
#include <set>
#include <utility>
#define ll long long
using namespace std;
 
int main() {
    int n;
    cin >> n;
    set<pair<ll, ll> > s;
    while (n--) {
        ll a, b;
        cin >> a >> b;
        s.insert(make_pair(b, a));
    }
    ll endTime = INT32_MIN, count = 0;
    for (set< pair<ll, ll> >::iterator it = s.begin(); it != s.end(); it++) {
        if (it->second >= endTime) {
            count++;
            endTime = (*it).first;
        }
    }
    cout << count;
}
