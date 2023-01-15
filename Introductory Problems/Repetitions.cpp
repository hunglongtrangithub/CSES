#include <iostream>
using namespace std;
#define ll long long

int main() {
    string s;
    cin >> s;
    ll ans = 1, count = 0; // count is the current number of consecutive characters
    char prev = 'A'; // prev is the previous character at a given position
    for (char c : s) {
        if (c == prev) {
            count++;
            ans = max(ans, count);
        } else {
            count = 1;
            prev = c;
        }
    }
    cout << ans;
}