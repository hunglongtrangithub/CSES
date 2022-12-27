#include <iostream>
#include <set>
#include <utility>
#define ll long long
using namespace std;
 
int main() {
    int n;
    cin >> n;
    set< pair<int, int> > s;
    int num = 0, best = -1;
    while (n--) {
        int a, b;
        cin >> a >> b;
        s.insert(make_pair(a, 1));
        s.insert(make_pair(b, -1));
    }
    for (set< pair<int, int> >::iterator it = s.begin(); it != s.end(); it++) {
        num += (*it).second;
        if (best < num) 
            best = num; 
    }
    cout << best << endl; 
}
