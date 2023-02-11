#include <iostream>
#include <set>
#include <utility>
using namespace std;
 
int main() {
    long n;
    cin >> n;
    multiset<pair<long, long>> movie_time;
    for (long i = 0; i < n; i++) {
        long start, end;
        cin >> start >> end;
        movie_time.insert({end, start}); // sort by end time
    }
    // we want to choose the movie that has the earliest ending time to have the most options for the next
    long end_time = 0, count = 0;
    for (pair<long, long> time : movie_time) {
        if (time.second >= end_time) { 
            count++;
            end_time = time.first; 
        }
    }
    cout << count;
    return 0;
}
