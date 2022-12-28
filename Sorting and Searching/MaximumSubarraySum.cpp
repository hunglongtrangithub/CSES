#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
 
int main() {
    ll n;
    cin >> n;
    vector<ll> vec(n);
    for (ll i = 0; i < n; i++) {
        cin >> vec[i];
    }
    ll localMax = -1, globalMax = INT32_MIN;
    for (ll i = 0; i < n; i++) {
        localMax = max(vec[i], vec[i] + localMax);
        globalMax = max(localMax, globalMax); 
    }
    cout << globalMax << endl;
}