#include <iostream>
#include <vector>
#include <set>
#define ll long long
using namespace std;
string check(vector<ll> X, vector<ll> Y, ll x, ll y) {
    int n = X.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        ll X1 = X[i], Y1 = Y[i], X2 = X[j], Y2 = Y[j];
        if (Y1 < Y2) {
            swap(X1, X2);
            swap(Y1, Y2);
        }
        if (Y1 == Y2) {
            if (min(X1, X2) < x && x < max(X1, X2) && y == Y1) {
                return "BOUNDARY";
            }
        } else if (Y2 <= y && y <= Y1) {
            if ((x-X1)*(Y2-y) - (X2-x)*(y-Y1) > 0) {
                count++;
            } else if ((x-X1)*(Y2-y) - (X2-x)*(y-Y1) == 0) {
                return "BOUNDARY";
            }
        }
    }
    if (count % 2 == 0) {
        return "OUTSIDE";
    } else {
        return "INSIDE";
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> X(n), Y(n);
    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
    }
    vector<ll> x(m), y(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < m; i++) {
        cout << check(X, Y, x[i], y[i]) << endl;
    }
}