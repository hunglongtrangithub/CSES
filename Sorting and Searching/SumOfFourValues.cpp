#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main() {
    long n, x;
    cin >> n >> x;
    vector<pair<long, long>> a(n);
    for (long i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    /*
    Loop through all possible pairs of indices (i, j) where i < j < n.
    For each pair, we want to find the indices (k, l) where k > j and l < n such that
    a[k].first + a[l].first = x - a[i].first - a[j].first. We can use binary search to find the indices k and l.
    */
    for (long k = 0; k < n; k++) {
        for (long i = k + 1; i < n; i++) {
            long target = x - a[i].first - a[k].first;
            long left = i + 1;
            long right = n - 1;
            while (left < right) {
                if (a[left].first + a[right].first > target) {
                    right--;
                } else if (a[left].first + a[right].first < target) {
                    left++;
                } else if (a[left].first + a[right].first == target) {
                    cout << a[k].second << " " << a[i].second << " " << a[left].second << " " << a[right].second;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}