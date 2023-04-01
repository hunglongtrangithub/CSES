#include <iostream>
#include <vector>
using namespace std;

int main() {
    long n, t;
    cin >> n >> t;
    vector<long> machines(n); 
    for (long i = 0; i < n; i++) {
        cin >> machines[i];
    }
    long left = 0;
    long right = long(1e18); // 10^18 = 1 * 10^9 * 10^9 (worst case: 1 machine, 10^9 items, 10^9 time)
    /*  
    For a given time in the range [left, right], we check if we are able to produce t items in that time, by finding
    maxmimally how many items we can produce in that time. If the number of items produced is smaller than t, it means the 
    time is too small to satisfy the condition, so we increase the time and check again. Eventually, we will find the 
    smallest time that can satisfy the condition, after which all other larger times will also satisfy the condition.
    We can apply binary search on the range [left, right] to find the smallest time that can satisfy the condition.
    Because there exists an optimal production plan where the time taken is minimized, the time we have found through 
    binary search is the minimum time, which is the answer.
    */ 
    while (left < right) {
        long mid = (left + right) / 2;
        long max_product = 0; // max number of items produced in time mid
        /* 
        The upper bound for max_product is (2 * 10^5) * (10^18 / 1) = 2 * 10^23, which is larger than 
        the maximum value of long (2^63 - 1). So we need to prevent overflow by stopping adding up max_product 
        when it is already >= t. 
        */
        for (long i = 0; i < n; i++) {
            max_product += mid / machines[i];
            if (max_product >= t) {
                break; 
            }
        }
        if (max_product >= t) {
            right = mid; // ignore numbers larger than mid
        } else {
            left = mid + 1; // ignore numbers smaller than or equal to mid
        }
    }
    // the search stops when left == right, which is the answer
    cout << left;
    return 0;
}