#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    long n;
    cin >> n;
    vector<long> arr(n);
    for (long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    /* 
    Kadane's algorithm:
    A certain subarray in the array is arr[i, j] where 0 <= i <= j < n. We consider a group all of the subarrays that end at the 
    current index j and find their maximum sum (local_max). local_max is the maximum sum of a subarray ending at the current 
    index j ([i, j] where i is from 0 to j). For each j, we have a local_max. global_max is the maximum sum of a subarray in the 
    entire array. We update global_max by comparing it to local_max at each j. 
    */
    long local_max = -1, global_max = INT64_MIN;
    for (long num : arr) {
        local_max = max(num, num + local_max);
        global_max = max(local_max, global_max); 
    }
    cout << global_max;
    return 0;
}