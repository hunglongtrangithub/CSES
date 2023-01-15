#include <iostream>
#include <set>
#include <utility>
#define ll long long
using namespace std;
 
int main() {
    ll n;
    cin >> n;
    set<pair<ll, ll> > s;
    int num = 0, best = -1;
    while (n--) {
        int a, b;
        cin >> a >> b;
        // put the arrival and leaving time of each customer on a timeline
        s.insert(make_pair(a, 1));
        s.insert(make_pair(b, -1));
    }
    // sweep line algorithm: we check the number of customers at each time when a customer leaves or arrives
    for (set<pair<ll, ll> >::iterator it = s.begin(); it != s.end(); it++) {
        num += it->second;
        if (best < num) 
            best = num; 
    }
    cout << best << endl; 
}
