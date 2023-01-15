#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
 
int main() {
    ll n, x, a;
    cin >> n >> x;
    vector<int> s(n), arr(n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        s[i] = a;
        arr[i] = a;
    }
    sort(s.begin(), s.end());
    ll i = 0, j = n - 1; // two pointers
    bool flag = true; // flag to check if there are two numbers that sum up to x
    while (i < j) {
        if (s[i] + s[j] > x) {
            j--;  
        } else if (s[i] + s[j] < x) {
            i++;
        } else {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "IMPOSSIBLE" << endl;
    else {
        vector<int>::iterator it1 = find(arr.begin(), arr.end(), s[i]);
        *it1 = 0; // avoid it1 == it2 when the two numbers are the same
        vector<int>::iterator it2 = find(arr.begin(), arr.end(), s[j]);
        cout << it1 - arr.begin() + 1 << " " << it2 - arr.begin() + 1; 
    }    
}