#include <iostream>
using namespace std;
#define ll long long
int main() {
    string s;
    cin >> s;
    int ans=1, count=0;
    char l='A';
    for (char d : s) {
        if (d==l) {
            ++count;
            ans=max(ans, count);
        } else {
            count=1;
            l=d;
        }
    }
    cout << ans;
}