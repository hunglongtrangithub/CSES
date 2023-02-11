#include <iostream>
#include <set>
#include <utility>
using namespace std;

int main() {
    long n, k;
    cin >> n >> k;
    multiset<pair<long, long>> movie_time;
    for (long i = 0; i < n; i++) {
        long start, end;
        cin >> start >> end;
        movie_time.insert({end, start}); // sort by end time
    }
    long count = 0;
    multiset<long> end_time; // end time of members
    for (long i = 0; i < k; i++) {
        end_time.insert(0); // initialize all members' end time to 0
    }
    /* We want to sort the movies by end time, so that after a member have watched a movie, 
    there will be the most choices for the next movie. For a movie, we want to find the member
    who can watch the movie with the latest end time, so that the other members who have earlier
    end times can choose to watch the movies with earlier start times. */
    for (pair<long, long> movie : movie_time) {
        // find the first member whose end time exceeds the start time of the movie
        auto member = end_time.upper_bound(movie.second); 
        if (member != end_time.begin()) { 
            member--; // the member who can watch the movie with the latest end time
            count++;
            end_time.erase(member); // remove the member from the set
            end_time.insert(movie.first); // add the member back to the set with the new end time
        }
    }
    cout << count;
    return 0;
}