#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    long n;
    cin >> n;
    vector<long> v(n);
    for (long i = 0; i < n; i++) {
        cin >> v[i];
    }
    set<long> s;
    long i = 0, j = 0, ans = 0;
    while (i < n && j < n) {
        while (j < n && s.count(v[j]) == 0) {
            s.insert(v[j]);
            j++;
        }
        if (j - i > ans) {
            ans = j - i;
        }
        while (i < n && v[i] != v[j]) {
            s.erase(v[i]);
            i++;
        }
        i++;
        j++;
    }
    cout << ans;
    return 0;
}