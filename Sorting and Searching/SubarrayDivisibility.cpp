#include <iostream>
#include <map>
using namespace std;

int main() {
    long n, a;
    cin >> n;
    map<long, long> m; // store all possible remainders when a prefix sum divided by n with the number of times they occur 
    m[0] = 1; // the prefix sum of the empty subarray is 0. The remainder of 0 divided by n is 0.
    long count = 0; 
    long sum = 0; // prefix sum
    /* Formula of the sum of a subarray: sum[i, j] = sum[0, j] - sum[0, i - 1]. n | sum[i, j] 
    means that sum[0, j] and sum[0, i - 1] have the same remainder when divided by n. So we look 
    for the previously saved remainder in the map that is equal to the current remainder. If there
    are any, we add the count of that remainder to the count variable. Finally, we increment the 
    count of the current remainder. */
    for (long i = 0; i < n; i++) {
        cin >> a;
        // update the current prefix sum
        sum += a; 
        // calculate the remainder of the current prefix sum (this formula is used to handle negative remainders)
        long remainder = (sum % n + n) % n; 
        count += m[remainder]; // add the count of the remainder that is equal to the current remainder
        m[remainder]++; // increment the count of the current remainder 
    }
    cout << count;
    return 0;
}