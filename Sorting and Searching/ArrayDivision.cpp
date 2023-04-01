#include <iostream>
#include <vector>
using namespace std;
 
int main() {
	long n, k;
	cin >> n >> k;
	vector<long> x(n);
	long max_element = INT64_MIN; // the maximum element in the array
	for (long i = 0; i < n; i++) {
	    cin >> x[i];
		max_element = max(max_element, x[i]);
	}
    // The subarray sum is at least the maximum element in the array, and at most the sum of all elements in the array.
	long left = max_element; 
	long right = 2 * long(10e14); // (2 * 10^5) * 10^9 = 2 * 10^14
    /* 
    For a number in the range [left, right], we check if we are able to split the array into k subarrays whose sums are 
    all less than or equal to the number, by finding how many subarrays we need to split the array into so that each 
    subarray sum is less than or equal to that number. If the count is greater than k, it means the number is too small to 
    satisfy the condition, so we increase the number and check again. Eventually, we will find the smallest number that 
    can satisfy the condition, after which all other larger numbers will also satisfy the condition. 
    We can apply binary search on the range [left, right] to find the smallest number that can satisfy the condition. 
    Because there exists an optimal division where the largest subarray sum is minimized, the number we have found through
    binary search is the minimum largest subarray sum, which is the answer. 
    */
	while (left < right) {
        long mid = (left + right) / 2; // the number we are checking
        long count = 1; // the number of subarrays we need to split the array into
        long sum = 0; // the sum of the current subarray
        for (long num : x) {
            // if the sum of the current subarray plus the next number is greater than mid, we need to split the array
            if (sum + num > mid) { 
                count++;
                sum = 0;
            }
            sum += num;
        }
        if (count > k) {
            left = mid + 1; // ignore numbers smaller than or equal to mid
        } else {
            right = mid; // ignore numbers larger than mid
        }
	}
    // the search stops when left == right, which is the answer
	cout << left;
  return 0;
}