#include <iostream>
#include <vector>
using namespace std;

int main() {
    long n, x;
    cin >> n >> x;
    vector<long> coins(n);
    for (long i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<long> dp(x + 1, 0); // dp[i] = number of ways to make sum i
    dp[0] = 1;
    /* 
    dp[i] = sum(dp[i - coins[j]]) for all j (ignore if i - coins[j] < 0). dp[i] = 0 means that there is no way to 
    make sum i. We can iterate through all indices i from 1 to x, and at each index i, we can iterate through all coins j 
    and add dp[i - coins[j]] to dp[i]. Note that i - coins[j] < i, so dp[i - coins[j]] has already been calculated
    before we calculate dp[i]. 
    */
    for (long i = 1; i <= x; i++) {
        for (long j = 0; j < n; j++) {
            if (i - coins[j] >= 0) {
                dp[i] += dp[i - coins[j]];
                dp[i] %= long(1e9 + 7);
            }
        }
    }
    cout << dp[x];
    return 0;
}