#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll min_diff = INT32_MAX, n;
vector<ll> apples;
ll total_apple_weight;

/* iterate through all possible combinations of apples (in the order from small index to large index)
by creating an iterator starting at every index (larger than the current index)
and adding the weight of the apple at that index to the current sum */
void recur_all_sums(ll index = -1, ll current_sum = 0) {
    min_diff = min(min_diff, abs(total_apple_weight - current_sum * 2));
    for (int i = index + 1; i < n; i++) {
        recur_all_sums(i, current_sum + apples[i]); 
    }
}
 
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll p;
        cin >> p;
        apples.push_back(p);
        total_apple_weight += p;
    } 
    recur_all_sums();
    cout << min_diff << endl;
}
