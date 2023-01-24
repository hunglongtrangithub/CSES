#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    long n;
    cin >> n;
    vector<long> v(n);
    for (long i = 0; i < n; i++) {
        v[i] = i + 1;
    }
    long check = 0; // index of the child
    while (check < long(v.size())) {
        if (check % 2 == 0) {
            v.push_back(v[check]);
        } else {
            cout << v[check] << ' ';
        }
        check++;
    }
    return 0;
}