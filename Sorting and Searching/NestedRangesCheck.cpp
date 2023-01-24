#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

//define a custom function to compare in the sort() function
bool compare(const pair<pair<long, long>, long> &a, const pair<pair<long, long>, long> &b) {
    if (a.first.first == b.first.first) {
        //sort by right bound in descending order if left bounds are equal
        return a.first.second > b.first.second; 
    }
    return a.first.first < b.first.first; //sort by left bound in ascending order
} 

int main() {
    long n, left, right;
    cin >> n;
    vector<pair<pair<long, long>, long>> ranges(n);
    vector<long> contains(n), contained(n);
    for (long i = 0; i < n; i++) {
        cin >> left >> right;
        ranges[i] = {{left, right}, i}; //keep the original index of the range to use it for the output
    }
    sort(ranges.begin(), ranges.end(), compare);
    //contained
    long right_bound_max = 0;
    for (long i = 0; i < n; i++) {
        if (ranges[i].first.second > right_bound_max) {
            // if the right bound of the current range is greater than the largest right bound of the previous ranges
            contained[ranges[i].second] = 0;
            right_bound_max = ranges[i].first.second;
        } else {
            contained[ranges[i].second] = 1;
        }
    }
    //contains
    long right_bound_min = INT32_MAX;
    for (long i = n - 1; i >= 0; i--) {
        if (ranges[i].first.second < right_bound_min) {
            // if the right bound of the current range is smaller than the smallest right bound of the previous ranges
            contains[ranges[i].second] = 0;
            right_bound_min = ranges[i].first.second;
        } else {
            contains[ranges[i].second] = 1;
        }
    }
    for (long i : contains) {
        cout << i << " ";
    }
    cout << endl;
    for (long i : contained) {
        cout << i << " ";
    }
    return 0;
}
