#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
int  main() {
    long n, k;
    cin >> n >> k;
    vector<long> arr(n);
    for (long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    map<long, long> m;
    long i = 0, j = 0; // i and j indicate the range of the current subarray arr[i, j]
    long count = 0; // counts the number of distinct values in the current subarray
    long more_than_k = 0; // count the number of subarrays with more than k distinct values
    /* Instead of looking for subarrays with at most k distinct values, we will look for the number of 
       subarrays with more than k distinct values. We use a map m to keep track of the frequency of the 
       current element and a count variable to keep track of the number of distinct values in the current 
       subarray arr[i, j]. 
       We increment j and update m and count accordingly. If count > k, then we know that every subarray 
       arr[i, l] where l > j also have more than k disinct values, so at that point we increment more_than_k 
       by n - j (the number of such subarrays). Then we increment i and update count, m, and more_than_k accordingly. 
       The final answer will be the number of all subarrays minus more_than_k. */
    while (j < n) {
        if (m[arr[j]] == 0) {
            count++;
        }
        m[arr[j]]++;
        while (count > k) {
            more_than_k += n - j;
            m[arr[i]]--;
            if (m[arr[i]] == 0) {
                count--;
            }
            i++;
        }
        j++;
    }
    cout << n * (n + 1) / 2 - more_than_k;
    return 0;
}