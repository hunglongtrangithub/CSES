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
        s.insert(make_pair(b, a)); // sort by end time
    }
    // greedy algorithm: we want to choose the movie that has the earliest ending time have most options for the next
    ll endTime = 0, count = 0;
    for (set<pair<ll, ll> >::iterator time = s.begin(); time != s.end(); time++) {
        if (time->second >= endTime) {
            count++;
            endTime = time->first;
        }
    }
    cout << count;
}
