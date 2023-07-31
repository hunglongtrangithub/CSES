#include <iostream>
#include <vector>
using namespace std;
#define long int // For some reason, using long instead of int gives a runtime error, so I have to use #define long int
int main() {
    long n, x;
    cin >> n >> x;
    vector<long> numpages(n), prices(n); // numpages: s, prices: h
    for (long i = 0; i < n; i++) {
        cin >> prices[i];
    }
    for (long i = 0; i < n; i++) {
        cin >> numpages[i];
    }
    vector<vector<long>> dp(n + 1, vector<long>(x + 1, 0)); 
    // dp[i][j] = maximum number of pages that can be bought with the first i books and j money
    /*
    Assume that we know the maximum number of pages that can be bought with the first i - 1 books and j money dp[i - 1][j].
    Then, in order to know the maximum number of pages that can be bought with the first i books and j money dp[i][j], we have two options:
    1. We do not buy the ith book. Then, the maximum number of pages that can be bought with the first i books and j money is 
    dp[i][j] = dp[i - 1][j].
    2. We buy the ith book. Then, we only have j - prices[i] money left. The maximum number of pages that can be bought with that money is 
    dp[i - 1][j - prices[i]]. So for j money, the maximum number of pages that can be bought with the first i books is 
    dp[i][j] = dp[i - 1][j - prices[i]] + numpages[i].
    If j >= prices[i], we choose the maximum of these two options: dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - prices[i]] + numpages[i]).
    If j < prices[i], then we cannot buy the ith book, so we only have option 1: dp[i][j] = dp[i - 1][j].
    In short: 
    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - prices[i]] + numpages[i]) if j >= prices[i], else dp[i][j] = dp[i - 1][j].
    */
   // We iterate through all books first so that each book is only considered once
   // the first i books
    for (long i = 1; i <= n; i++) { 
        // j money
        for (long j = 1; j <= x; j++) { 
            // we take price and number of pages at i - 1 because books are 0-indexed
            if (j >= prices[i - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - prices[i - 1]] + numpages[i - 1]); 
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][x];
    return 0;
}