#include <iostream>
#include <vector>
#define ll long long
using namespace std;
 
int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) 
        v[i] = i + 1;
    ll check = 0; // index of the child
    while (check < v.size()) {
        if (check % 2 == 0) 
            v.push_back(v[check]);
        else 
            cout << v[check] << ' ';
        check++;
    }
}