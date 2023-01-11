#include <iostream>
using namespace std;
#define ll long long
int main() {
    string s;
    cin >> s;
    ll ans = 1, count = 0; // count is the current number of consecutive characters
    char l = 'A';
    for (int i = 0; i < int(s.size()); i++) {
        if (s[i] == l) {
            count++;
            ans = max(ans, count);
        } else {
            count = 1;
            l = s[i];
        }
    }
    cout << ans;
}