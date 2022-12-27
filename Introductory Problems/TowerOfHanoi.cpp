#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
void f(int k, int s, int m, int e) {
    if (k==1) cout << s << " " << e << endl;
    else {
        f(k-1, s, e, m);
        f(1, s, m, e);
        f(k-1, m, s, e);
    }
}
int main() {
    int n;
    cin >> n;
    cout << int(pow(2,n))-1 << endl;
    f(n, 1, 2, 3);
}