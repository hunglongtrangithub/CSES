#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    long n;
    cin >> n;
    vector<long> dp(n + 1, 0); // dp[i] = number of ways to get sum i
    dp[0] = 1;
    /* 
    The number of ways to get sum i is the sum of the number of ways to get sum i - j for j = 1 to 6:
    dp[i] = sum of dp[i - j] for j = 1 to 6 (or from 1 to i if i < 6). 
    */
    for (long i = 1; i <= n; i++) {
        for (long j = 1; j <= 6; j++) {
            if (i - j >= 0) { // ignore if i - j is negative 
                dp[i] += dp[i - j];
                dp[i] %= long(1e9 + 7);
            }
        }
    }
    cout << dp[n];
    return 0;
}