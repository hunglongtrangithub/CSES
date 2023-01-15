#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
 
int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll localMax = -1, globalMax = INT32_MIN;
    for (ll num : arr) {
        localMax = max(num, num + localMax);
        globalMax = max(localMax, globalMax); 
    }
    cout << globalMax << endl;
}