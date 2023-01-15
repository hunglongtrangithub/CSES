#include <iostream>
#include <vector>
#define ll long long
using namespace std;
 
ll dice_combination(int n, vector<ll> &memo) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
	if (memo[n - 1] != 0) {
        return memo[n - 1];
    }
    ll ans = 0;
    for (int i = 1; i <= 6; i++) {
        ans += dice_combination(n - i, memo) % int(1e9 + 7);
    }
	memo[n - 1] = ans % int(1e9+7);
    return memo[n - 1];
}
int main() {
    int n;
    cin >> n;
	vector<ll> memo(1e6, 0);
    cout << dice_combination(n, memo);
    return 0;
}