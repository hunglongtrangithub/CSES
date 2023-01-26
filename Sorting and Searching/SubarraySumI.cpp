#include <iostream>
#include <vector>
using namespace std;

int main() {
    long n, x;
    cin >> n >> x;
    vector<long> a(n);
    for (long i = 0; i < n; i++) {
        cin >> a[i];
    }
    long i = 0, j = 0; // a[i], a[i + 1], ..., a[j] is the current subarray
    long sum = 0; // sum of the current subarray
    long count = 0; // number of subarrays with sum = x
    while (j < n) {
        // add a[j] to the current subarray
        sum += a[j];
        // remove elements from the beginning of the current subarray until the sum is < x
        while (sum >= x) { 
            if (sum == x) {
                count++;
            }
            sum -= a[i];
            i++;
        }
        j++;
    }
    // the time complexity is O(n) because each element is added and removed at most once
    cout << count;
    return 0;
}