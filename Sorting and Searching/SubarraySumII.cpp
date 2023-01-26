#include <iostream>
#include <map>
using namespace std;

int main() {
    long n, x, a;
    cin >> n >> x;
    map<long, long> prefix_sums; // store all prefix sums with their counts
    prefix_sums[0] = 1; // the prefix sum of the empty subarray is 0
    long count = 0;
    long sum = 0; // prefix sum
    /* Formula of the sum of a subarray: sum[i, j] = sum[0, j] - sum[0, i - 1] -> sum[0, i - 1] = sum[0, j] - sum[i, j].
    For sum[i, j] = x, sum[0, i - 1] = sum[0, j] - x.
    We make a map to save all of the previously calculated prefix sums with their counts.
    When going through each number in the array, we calculate the current prefix sum with the variable sum. 
    Then we look for the previously saved prefix sum in the map that is equal to the current prefix sum minus x. 
    If there are any, we add the count of that prefix sum to the count variable.
    Finally, we increment the count of the current prefix sum or add it to the map if it is not present. */
    for (long i = 0; i < n; i++) {
        cin >> a;
        sum += a; // update the current prefix sum
        count += prefix_sums[sum - x]; // add the count of the prefix sum that is x less than the current prefix sum
        prefix_sums[sum]++; // increment the count of the current prefix sum or add it to the map if it is not present
    }
    cout << count;
    return 0;
}