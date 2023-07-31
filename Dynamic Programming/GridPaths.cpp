#include <iostream>
#include <vector>
using namespace std;

int main() {
    long n;
    cin >> n;
    vector<vector<bool>> trap(n, vector<bool>(n, 0)); // stores the trap locations (1 if trap, 0 if not)
    vector<vector<long>> dp(n, vector<long>(n, 0)); // dp[i][j] stores the number of paths to reach (i, j)
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '*') {
                trap[i][j] = 1;
            } else {
                trap[i][j] = 0;
            }
        }
    }
    if (trap[0][0]) {
        cout << 0;
        return 0;
    } else {
        dp[0][0] = 1;
    }
    /* 
    The number of paths to reach (i, j) is the sum of the number of paths to reach (i - 1, j) and (i, j - 1)
    (because we can only move down or right):
    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
    */
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < n; j++) {
            if (trap[i][j]) {
                continue;
            }
            if (i - 1 >= 0 && !trap[i - 1][j]) {
                dp[i][j] += dp[i - 1][j];
            }
            if (j - 1 >= 0 && !trap[i][j - 1]) {
                dp[i][j] += dp[i][j - 1];
            }
            dp[i][j] %= long(1e9 + 7);
        } 
    }
    cout << dp[n - 1][n - 1];
    return 0;
}