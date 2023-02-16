#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
long min_coins(long desired_sum, vector<long> &coins, long n, vector<vector<long>> &memo, long start = 0, long count = 0) {
    if (desired_sum == 0) {
        return count;
    }
    if (memo[desired_sum][start] != 0) {
        return memo[desired_sum][start];
    }
    long min_count = INT64_MAX;
    for (long i = start; i < n; i++) {
        if (desired_sum - coins[i] >= 0) {
		    long check = min_coins(desired_sum - coins[i], coins, n, memo, i, count + 1);  
            if (check < min_count) {
                min_count = check;
            }
        }
    }
    memo[desired_sum][start] = min_count == INT64_MAX ? -1 : min_count;
    return memo[desired_sum][start];
}
 
int main() {
    long n, x;
    cin >> n >> x;
    vector<long> coins(n);
    for (long i = 0; i < n; i++) {
        long c;
        cin >> c;
        coins[i] = c;
    }
    sort(coins.begin(), coins.end(), greater<long>());
    vector<vector<long>> memo(long(1e6) + 1, vector<long>(n, 0));
    cout << min_coins(x, coins, n, memo);
    return 0;
}