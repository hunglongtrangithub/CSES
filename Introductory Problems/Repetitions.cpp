#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    long ans = 1, count = 0; // count is the current number of consecutive characters
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
    return 0;
}