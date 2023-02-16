#include <iostream>
#include <vector>
using namespace std;
 
// recursive solution with memoization
long dice_combination(long n, vector<long> &memo) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
	if (memo[n] != 0) {
        return memo[n];
    }
    long ans = 0;
    for (long i = 1; i <= 6; i++) {
        ans += dice_combination(n - i, memo) % long(1e9 + 7);
    }
	memo[n] = ans % long(1e9 + 7); // save the result to avoid recomputation
    return memo[n];
}
int main() {
    long n;
    cin >> n;
	vector<long> memo(long(1e6 + 1), 0);
    cout << dice_combination(n, memo);
    return 0;
}