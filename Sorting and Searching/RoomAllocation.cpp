#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    long n;
    cin >> n;
    vector<pair<pair<long, long>, long>> days(n); // keeping the arrival and departure day for each guest, along with the index of the guest
    vector<long> rooms(n); // keeping the room number for each guest
    long max_room_num = 0;
    for (long i = 0; i < n; i++) {
        long a, b;
        cin >> a >> b;
        days[i] = {{a, b}, i};
    }
    sort(days.begin(), days.end());
    set<pair<long, long>> right_bound{{INT64_MAX, 0}}; // keeping the departure day and room number for each current room
    for (pair<pair<long, long>, long> i : days) {
        if (i.first.first <= right_bound.begin()->first) {
            max_room_num++;
            rooms[i.second] = max_room_num;
            right_bound.insert({i.first.second, max_room_num});
        } else {
            rooms[i.second] = right_bound.begin()->second;
            right_bound.erase(right_bound.begin());
            right_bound.insert({i.first.second, rooms[i.second]});
        }
    }
    cout << max_room_num << endl;
    for (long i : rooms) {
        cout << i << " ";
    }
    return 0;
}