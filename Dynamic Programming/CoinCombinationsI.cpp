#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<int> dp(x + 1, 0); // dp[i] = number of ways to make sum i
    dp[0] = 1;
    /* dp[i] = sum(dp[i - coins[j]]) for all j (ignore if i - coins[j] < 0). dp[i] = 0 means that there is no way to 
    make sum i. We can iterate through all indices i from 1 to x, and at each index i, we can iterate through all coins j 
    and add dp[i - coins[j]] to dp[i]. Note that i - coins[j] < i, so dp[i - coins[j]] has already been calculated
    before we calculate dp[i]. */
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0) {
                dp[i] += dp[i - coins[j]];
                dp[i] %= long(1e9 + 7);
            }
        }
    }
    cout << dp[x];
    return 0;
}