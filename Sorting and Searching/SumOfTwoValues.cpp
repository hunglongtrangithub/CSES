#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
    int n, x, a;
    cin >> n >> x;
    vector<int> s(n), arr(n);
    for (int i=0; i<n; i++) {
        cin >> a;
        s[i] = a;
        arr[i] = a;
    }
    sort(s.begin(), s.end());
    int i = 0, j = n-1;
    int c = 0;
    while (i < j) {
        if (s[i] + s[j] > x) {
            j--;  
        } else if (s[i] + s[j] < x) {
            i++;
        } else {
            c++;
            break;
        }
    }
    if (c == 0)
        cout<<"IMPOSSIBLE"<<endl;
    else {
        vector<int>::iterator it1 = find(arr.begin(), arr.end(), s[i]);
        *it1 = 0;
        vector<int>::iterator it2 = find(arr.begin(), arr.end(), s[j]);
        cout << it1 - arr.begin() + 1 << ' ' << it2 - arr.begin() + 1; 
    }    
}