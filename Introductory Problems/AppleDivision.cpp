#include <iostream>
#include <vector>
using namespace std;

long min_diff = INT64_MAX, n;
vector<long> apples;
long total_apple_weight;

/* 
iterate through all possible combinations of apples (in the order from small index to large index)
by creating an iterator starting at every index (larger than the current index)
and adding the weight of the apple at that index to the current sum 
*/
void recur_all_sums(long index=-1, long current_sum=0) {
    min_diff = min(min_diff, abs(total_apple_weight - current_sum * 2));
    for (long i = index + 1; i < n; i++) {
        recur_all_sums(i, current_sum + apples[i]); 
    }
}
 
int main() {
    cin >> n;
    for (long i = 0; i < n; i++) {
        long p;
        cin >> p;
        apples.push_back(p);
        total_apple_weight += p;
    } 
    recur_all_sums();
    cout << min_diff;
    return 0;
}
