#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

//define a custom function to compare in the sort() function
bool compare(const pair<pair<ll, ll>, ll> &a, const pair<pair<ll, ll>, ll> &b) {
    if (a.first.first == b.first.first) 
        //sort by right bound in descending order if left bounds are equal
        return a.first.second > b.first.second; 
    return a.first.first < b.first.first; //sort by left bound in ascending order
} 
int main() {
    ll n, left, right;
    cin >> n;
    vector<pair<pair<ll, ll>, ll> > ranges(n);
    vector<ll> contains(n), contained(n);
    for (int i = 0; i < n; i++) {
        cin >> left >> right;
        ranges[i] = make_pair(make_pair(left, right), i);
    }
    sort(ranges.begin(), ranges.end(), compare);
    //contained
    ll right_bound_max = 0;
    for (int i = 0; i < n; i++) {
        if (ranges[i].first.second > right_bound_max) {
            contained[ranges[i].second] = 0;
            right_bound_max = ranges[i].first.second;
        } else {
            contained[ranges[i].second] = 1;
        }
    }
    //contains
    ll right_bound_min = INT32_MAX;
    for (int i = n-1; i >= 0; i--) {
        if (ranges[i].first.second < right_bound_min) {
            contains[ranges[i].second] = 0;
            right_bound_min = ranges[i].first.second;
        } else {
            contains[ranges[i].second] = 1;
        }
    }
    for (int i = 0; i < n; i++) 
        cout << contains[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) 
        cout << contained[i] << " ";
}
