#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    long n;
    cin >> n;
    vector<long> dp(n + 1, INT64_MAX); // dp[i] = minimum number of steps to make i to 0
    dp[0] = 0;
    /* 
    The minimum number of steps to make i to 0 is the minimum of the minimum number of steps to make
    i - j to 0 for j = each digit in i, plus 1:
    dp[i] = (min of dp[i - j] for j = each digit in i) + 1.
    */
    for (long i = 1; i <= n; i++) {
        long temp = i;
        while (temp > 0) {
            long digit = temp % 10;
            if (digit != 0 && i - digit >= 0) {
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
            temp /= 10;
        }
    }
    cout << dp[n];
    return 0;
}