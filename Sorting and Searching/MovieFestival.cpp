#include <iostream>
#include <set>
#include <utility>
using namespace std;
 
int main() {
    long n;
    cin >> n;
    set<pair<long, long>> s;
    for (long i = 0; i < n; i++) {
        long a, b;
        cin >> a >> b;
        s.insert({b, a}); // sort by end time
    }
    // we want to choose the movie that has the earliest ending time to have the most options for the next
    long endTime = 0, count = 0;
    for (pair<long, long> time : s) {
        if (time.second >= endTime) {
            count++;
            endTime = time.first;
        }
    }
    cout << count;
    return 0;
}
