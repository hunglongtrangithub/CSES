#include <iostream>
#include <vector>
#include <set>
using namespace std;
 
int main() {
    long n, a, b;
    cin >> n >> a >> b;
    vector<long> prefix_sums(n + 1);
    prefix_sums[0] = 0;
    for (long i = 0; i < n; i++) {
        long x;
        cin >> x;
        prefix_sums[i + 1] = prefix_sums[i] + x;
    }
    /* 
    We organize the collection S of all possible subarrays into groups of subarrays that start at the same index and 
    have the lengths vary from a to b. To be precise, S = {S_i | 0 <= i <= n - b} + {s_i | n - b + 1 <= i <= n - a}, where 
    S_i = {prefix_sums[j] - prefix_sums[i] | i + a <= j <= i + b}, s_i = {prefix_sums[j] - prefix_sums[i] | i + a <= j <= n}.
    For a certain index i, prefix_sums[i] is constant for all subarrays in S_i or s_i, so we can find the maximum subarray
    sum in S_i or s_i by finding the maximum prefix_sum[j] in S_i or s_i. We can do this by using a multiset that stores 
    all prefix_sums[j] in S_i or s_i and find the maximum with the rbegin() function. We can then iterate through all 
    possible i and find the maximum subarray sum in S. This will be done in O(nlogn) time.
    */
    long max_sum = -2 * long(1e14) + 1;
    multiset<long> s; 
    for (long i = a; i <= b; i++) {
        s.insert(prefix_sums[i]);
    }
    for (long i = 0; i <= n - a; i++) {
        // Find the maximum subarray sum in S_i or s_i and update max_sum with that value minus prefix_sums[i].
        max_sum = max(max_sum, *s.rbegin() - prefix_sums[i]); 
        // Update the multiset by removing the prefix_sums[i + a] and adding the prefix_sums[i + b + 1] if it exists.
        s.erase(s.find(prefix_sums[i + a]));
        // If i + b + 1 > n, then the multiset will only contain prefix_sums[j] for j in [i + a, n].
        if (i + b + 1 <= n) {
            s.insert(prefix_sums[i + b + 1]);
        }
    }
    cout << max_sum;
    return 0;
}