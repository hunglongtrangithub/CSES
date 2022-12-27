#include <iostream>
#include <utility>
#include <vector>
#include <set>
using namespace std;
#define ll long long

int main() {
    ll n, start, end;
    cin >> n;
    vector< pair<ll, ll> > input;
    set< pair<ll, ll> > set;
    vector<ll> ans1(n), ans2(n);
    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        set.insert(make_pair(start, end));
        input.push_back(make_pair(start, end));
    }
    for (int i = 0; i < n; i++) {
        pair<ll, ll> range = input[i];
        auto it = set.find(range);
        auto pivot = it;
        //first answer
        it++;
        if (it == set.end()) 
            ans1[i] = 0;
        while (it->second > pivot->second) 
            it++;
        if (it == set.end())
            ans1[i] = 0;
        else 
            ans1[i] = 1;
        //second answer
        it--;
        if (it == set.end()--)
            ans2[i] = 0;
        while (it->second > pivot->second) 
            it++;
        if (it == set.end())
            ans1[i] = 0;
        else 
            ans1[i] = 1;

    }
}