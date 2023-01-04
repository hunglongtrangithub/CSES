#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;
    vector<pair<pair<ll, ll>, ll> > days(n); //keeping the arrival and departure day for each guest
    vector<ll> rooms(n); //keeping the room number for each guest
    ll max_room_num = 0;
    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        days[i] = make_pair(make_pair(a, b), i);
    }
    sort(days.begin(), days.end());
    set<pair<ll, ll> > right_bound; //keeping the departure day and room number for each current room
    right_bound.insert(make_pair(INT32_MAX, 0)); // first: departure day, second: room number
    for (ll i = 0; i < n; i++) {
        if (days[i].first.first <= right_bound.begin()->first) {
            max_room_num++;
            rooms[days[i].second] = max_room_num;
            right_bound.insert(make_pair(days[i].first.second, max_room_num));
        } else {
            rooms[days[i].second] = right_bound.begin()->second;
            right_bound.erase(right_bound.begin());
            right_bound.insert(make_pair(days[i].first.second, rooms[days[i].second]));
        }
    }
    cout << max_room_num << endl;
    for (ll i = 0; i < n; i++)
        cout << rooms[i] << " ";
}