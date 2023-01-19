#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += t[i];
    }
    /* Sort the reading time in ascending order. No matter how we arrange the reading time of the books, the total time 
    cannot be less than the sum of the reading time of all the books. In the case that t[n - 1] < sum / 2, we have the 
    following configuration of the reading schedule for Kotivalo and Justiina, where no one has to wait for another:
    1. Kotivalo: t[0], t[1], ..., t[n - 2], t[n - 1]
    2. Justiina: t[n - 1], t[0], t[1], ..., t[n - 2]
    This configuration works because the there is no overlap between the reading time of any books Kotivalo and Justiina:
    For t[n - 1], Justiina finishes reading t[n - 1] at t[n - 1] and Kotivalo starts reading t[n - 1] at sum - t[n - 1].
    Because t[n - 1] < sum / 2 <=> t[n - 1] < sum - t[n - 1], Justiina finishes reading t[n - 1] before Kotivalo starts.
    For t[i] (0 <= i <= n - 2), we have:
    Kotivalo finishes reading t[i] at t[0] + ... + t[i - 1] + t[i], 
    and Jutiina starts reading t[i] at t[n - 1] + t[0] + ... + t[i - 1].
    Because t[n - 1] > t[i] for 0 <= i <= n - 2 (because t is sorted in ascending order), Kotivalo finishes reading t[i]
    before Justiina starts reading t[i]. 
    Thus, there is no overlap between the reading time of any books between Kotivalo and Justiina, and the total reading
    time is sum.

    In the case that the reading time of the last book is larger than half the sum of the reading time all the books, we
    let Kotivalo read the last book and Justiina read the rest of the books, and when Kotivalo finishes, Justiina starts
    reading the last book and Kotivalo starts reading the rest of the books. The total reading time is t[n - 1] * 2.

    In short, if 2 * t[n - 1] < sum, the total reading time is sum. Otherwise, the total reading time is t[n - 1] * 2.
    This means that the total reading time is max(sum, t[n - 1] * 2).
    */
    ll ans = max(sum, t[n - 1] * 2);
    cout << ans << endl;
}