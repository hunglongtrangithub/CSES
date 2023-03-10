#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long n, m, k; // n = number of applicants, m = number of apartments, k = maximum difference
    cin >> n >> m >> k;
    vector<long> a(n), b(m);
    for (long i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (long i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long x = 0, y = 0, ans = 0;
    // x = index of the applicant, y = index of the apartment
    while (x < n && y < m) {
        if (b[y] > a[x] + k) { // if the apartment is too big, move to the next applicant
            x++;
        } else if (b[y] < a[x] - k) { // if the apartment is too small, move to the next apartment
            y++;
        } else { // if the apartment is suitable, move to the next applicant and apartment
            ans++;
            x++;
            y++;
        }
    }
    cout << ans;
    return 0;
}