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
	// Do binary search on the array a to find the indices (left, right) such that a[left].first + a[right].first = x.
	long left = 0;
	long right = n - 1;
	while (left < right) {
		if (a[left].first + a[right].first > x) {
			right--;
		} else if (a[left].first + a[right].first < x) {
			left++;
		} else if (a[left].first + a[right].first == x) {
			cout << a[left].second << " " << a[right].second;
			return 0;
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}
