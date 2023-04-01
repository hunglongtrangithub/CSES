#include <iostream>
using namespace std;

int main() {
    long n, ans = 0;
    cin >> n;
    /* 
    Let f(p) = the exponent of p in the prime factorization of n!.
    [n/p] = the number of multiples of p that are less than or equal to n
    [[n/p]/p] = the number of multiples of p^2 that are less than or equal to n
    [[[n/p]/p]/p] = the number of multiples of p^3 that are less than or equal to n
    ...
    --> f(p) = [n/p] + [[n/p]/p] + [[[n/p]/p]/p] + ...
    The number of trailing zeros in n! is min(f(2), f(5)).
    It is easy to see that f(2) > f(5), so the number of trailing zeros in n! is f(5).
    */
    while (n > 0) {
        n /= 5;
        ans += n;
    }
    cout << ans;
    return 0;
}
