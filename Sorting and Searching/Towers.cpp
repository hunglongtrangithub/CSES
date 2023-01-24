#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    long n;
    cin >> n;
    vector<long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    multiset<long> check;
    check.insert(v[0]);
    for (long i = 1; i < n; i++) {
        multiset<long>::iterator it = check.upper_bound(v[i]);
        if (it != check.end()) {
            check.erase(it);
        }
        check.insert(v[i]);
    }
    cout << check.size();
    return 0;
}