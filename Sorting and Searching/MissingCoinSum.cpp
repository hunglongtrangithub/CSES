#include <iostream>
#include <set>
using namespace std;

int main() {
    long n, x;
    multiset<long> s; // the set of coins
    cin >> n;
    for (long i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }
    long sum = 0; // the maximum sum of coins that can be made using a subset of the coins
    for (long coin : s) {
        if (coin > sum + 1) {
            break;
        } else {
            sum += coin;
        }
    }
    cout << sum + 1; // the smallest number that cannot be made using a subset of the coins
    return 0;
}