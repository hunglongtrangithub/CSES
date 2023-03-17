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
    vector<long> dp(x + 1, INT64_MAX); // dp[i] = minimum number of coins to get sum i, INT64_MAX if not possible
    dp[0] = 0;
    // dp[i] = (min of dp[i - coins[j]] for j = 1 to n) + 1
    for (long i = 1; i <= x; i++) {
        for (long j = 0; j < n; j++) {
            if (i - coins[j] >= 0) {
                dp[i] = min(dp[i], dp[i - coins[j]]);
            }
        }
        if (dp[i] != INT64_MAX) { // if it is possible to get sum i
            dp[i]++;
        }
    }
    cout << (dp[x] == INT64_MAX ? -1 : dp[x]);
}