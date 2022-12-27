#include <iostream>
#include <vector>
#define ll long long
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) 
        v[i] = i + 1;
    int check = 0;
    while (check < v.size()) {
        if (check % 2 == 0) 
            v.push_back(v[check]);
        else 
            cout << v[check] << ' ';
        check++;
    }
}