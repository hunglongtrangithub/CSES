#include <iostream>
#include <set>
#include <utility>
using namespace std;
 
int main() {
    long n;
    cin >> n;
    set<pair<long, long>> s;
    long num = 0, best = -1;
    for (long i = 0; i < n; i++) {
        long a, b;
        cin >> a >> b;
        // put the arrival and leaving time of each customer on a timeline
        s.insert({a, 1});
        s.insert({b, -1});
    }
    // sweep line algorithm: we check the number of customers at each time when a customer leaves or arrives
    for (pair<long, long> time : s) {
        num += time.second;
        if (best < num) {
            best = num; 
        }
    }
    cout << best;
    return 0; 
}
