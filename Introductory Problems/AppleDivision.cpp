#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define ll long long
ll res=INT64_MAX, n;
vector<ll> vec;
ll s;
void recur_all_sums(ll index=0, ll current_sum=0) {
    res=min(res, abs(s-current_sum*2));
    for (int i=index+1; i<n; i++) recur_all_sums(i, current_sum+vec[i]);
}
int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        ll p;
        cin >> p;
        vec.push_back(p);
        s+=p;
    } 
    recur_all_sums();
    cout << res;
}
