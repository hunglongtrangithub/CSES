#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ll n, a, d; // n = number of tasks, a = time to complete task, d = deadline
    cin >> n;
    vector<pair<ll, ll> > tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> d;
        tasks[i] = make_pair(a, d);
    }
    /* reward = sum(d - f) = sum(d) - sum(f). We see that sum(d) is a constant, 
    so maximize reward we need to minimize sum(f). Moreovew, sum(f) = (n*a_1 + (n-1)a_2 + ... + a_n), 
    so a_1, a_2, ..., a_n must be values that follows an increasing order. So we just need to sort the tasks 
    by the duration of the tasks and add up the reward in that order. */
    sort(tasks.begin(), tasks.end());
    ll finish_time = 0, reward = 0;
    for (int i = 0; i < n; i++) {
        finish_time += tasks[i].first; 
        reward += tasks[i].second - finish_time;
    }
    cout << reward;
}