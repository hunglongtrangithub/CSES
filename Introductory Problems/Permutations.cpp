#include <iostream>
using namespace std;
#define ll long long
int main() {
    ll n, a;
    cin >> n;
    if (n>3) {
        a=n-1;
        while (a>0) {
            cout << a << " ";
            a -= 2;
        }
        a=n;
        while (a>0) {
            cout << a << " ";
            a -= 2;
        }
    }
    else if (n==1) cout << 1;
    else cout << "NO SOLUTION";
}