#include <set>
#include <iostream>
using namespace std;

int main() {
    long n;
    cin >> n;
    long x;
    set<long> s;
    for (long i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }
    cout << s.size();
    return 0;
}