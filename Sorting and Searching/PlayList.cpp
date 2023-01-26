#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    long n;
    cin >> n;
    vector<long> v(n);
    for (long i = 0; i < n; i++) {
        cin >> v[i];
    }
    set<long> s;
    long i = 0, j = 0, ans = 0;
    // use two pointers to keep track of the current subarray [i, j - 1]
    while (i < n && j < n) {
        // move to the next element it is not present in the subarray until we meet a duplicate
        while (j < n && s.count(v[j]) == 0) {
            s.insert(v[j]);
            j++;
        }
        // update the maximum length of the subarray without duplicates
        ans = max(ans, j - i);
        // remove elements from the left until we meet the element that is equal to the duplicate
        while (i < n && v[i] != v[j]) {
            s.erase(v[i]);
            i++;
        }
        // translate the whole subarray to the right by one element
        i++;
        j++;
    }
    cout << ans;
    return 0;
}