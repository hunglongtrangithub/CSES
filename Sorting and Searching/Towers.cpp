#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    long n;
    cin >> n;
    vector<long> v(n); // the height of each tower
    for (long i = 0; i < n; i++) {
        cin >> v[i];
    }
    multiset<long> check;
    check.insert(v[0]); // the first tower is always visible
    for (long i = 1; i < n; i++) {
        multiset<long>::iterator it = check.upper_bound(v[i]);
        if (it != check.end()) { // if there is a tower with height greater than v[i], remove it
            check.erase(it);
        }
        check.insert(v[i]); // add v[i] to the set
    }
    cout << check.size(); // the number of towers in the set is the number of visible towers
    return 0;
}