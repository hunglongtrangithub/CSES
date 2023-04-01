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
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    /*
    Loop through all possible index i < n.
    For each index i, we want to find the indices (left, right) where left > i and right < n such that
    a[left].first + a[right].first = x - a[i].first. We can use binary search to find the indices left and right.
    */
    for (long i = 0; i < n; i++) {
        long target = x - a[i].first;
        long left = i + 1;
        long right = n - 1;
        while (left < right) {
            if (a[left].first + a[right].first > target) {
                right--;
            } else if (a[left].first + a[right].first < target) {
                left++;
            } else if (a[left].first + a[right].first == target) {
                cout << a[i].second + 1 << " " << a[left].second + 1 << " " << a[right].second + 1;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}