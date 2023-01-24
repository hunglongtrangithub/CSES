#include <iostream>
#include <vector>
using namespace std;
 
int check(vector<long> &v, int c, int d) {
    if (c - d == 1) {
        return (v[c - 2] > v[c - 1]) + (v[c - 1] > v[c]) + (v[c] > v[c + 1]);
    }
    if (d - c == 1) {
        return (v[d - 2] > v[d - 1]) + (v[d - 1] > v[d]) + (v[d] > v[d + 1]);
    }
    return (v[c - 1] > v[c]) + (v[c] > v[c + 1]) + (v[d - 1] > v[d]) + (v[d] > v[d + 1]);
}
 
int main() {
    long n, m, x;
    cin >> n >> m;
    vector<long> v1(n + 2), v2(n + 2); // v1: index -> value, v2: value -> index
    v1[0] = v2[0] = INT32_MAX;
    v1[n + 1] = v2[n + 1] = INT32_MAX;
    for (long i = 1; i <= n; i++) {
        cin >> x;
        v1[i] = x;
        v2[x] = i;
    }
    // compute the number of rounds for the initial array
    long ans = 0;
    for (long i = 0; i < n; i++) {
        if (v2[i] > v2[i + 1]) {
            ans++;
        }
    }
    for (long i = 0; i < m; i++) {
        long a, b;
        cin >> a >> b;
        long c = v1[a], d = v1[b]; // the values at index a and b in the array
        ans -= check(v2, c, d);
        // swap 
        v2[c] = b;
        v2[d] = a;
        v1[a] = d;
        v1[b] = c;
        ans += check(v2, c, d);
        cout << ans << endl;
    }
    return 0;  
}