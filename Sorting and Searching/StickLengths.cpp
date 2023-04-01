#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long n, ans = 0;
    cin >> n;
    vector<long> v(n);
    for (long i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    /* 
    The mininum total cost is when all the sticks have the same length as the median stick. 
    Any other specified length will result in a higher cost (== the cost of moving the sticks 
    to the median length plus the cost of moving the median stick to that specified length).
    The minimum cost is the sum of the differences between the median stick and the other sticks,
    which is the same as the difference between the sum of the lengths longer than the median 
    and the sum of the lengths shorter than the median. 
    */
    for (long i = 0; i < n / 2; i++) {
        ans += v[i + n / 2 + n % 2] - v[i];
    } 
    cout << ans;
    return 0;
}