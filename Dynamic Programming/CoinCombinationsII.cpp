#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long n, x;
    cin >> n >> x;
    vector<long> coins(n);
    for (long i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<long> dp(x + 1, 0); // dp[i] = number of distinct ways to make sum i
    dp[0] = 1;
    /* 
    dp[i] = sum(dp[i - coins[j]]) for all j (ignore if i - coins[j] < 0). dp[i] = 0 means that there is no way to
    make sum i. We iterate through all coins j and add dp[i - coins[j]] to dp[i] for all i >= coins[j]. Note that
    i - coins[j] < i, so dp[i - coins[j]] is already calculated before we calculate dp[i]. Also note that because we
    go through each coin first, it is guaranteed that each coin is only considered once and in order, and thus dp[i] 
    is the number of distinct ways to make sum i. 
    */
    for (long j = 0; j < n; j++) {
        for (long i = 1; i <= x; i++) {
            if (j - coins[i] >= 0) {
                dp[j] = (dp[j] + dp[j - coins[i]]) % long(1e9 + 7);
            }
        }
    }
    cout << dp[x];
    return 0;
}