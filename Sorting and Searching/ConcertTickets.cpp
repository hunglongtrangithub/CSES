#include <iostream>
#include <set>
using namespace std;

int main() {
    long n, m;
    cin >> n >> m;
    multiset<long> s;
    for (long i = 0; i < n; i++) {
        long h;
        cin >> h;
        s.insert(h);
    }
    for (long i = 0; i < m; i++) {
        long t;
        cin >> t;
        multiset<long>::iterator it = s.upper_bound(t);
        if (it == s.begin()) {
            cout << -1 << endl;
        }
        else {
            it--;
            cout << *it << endl;
            s.erase(it);
        }
    }
    return 0;
}