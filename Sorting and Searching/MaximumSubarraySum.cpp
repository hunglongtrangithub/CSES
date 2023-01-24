#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    long n;
    cin >> n;
    vector<long> arr(n);
    for (long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long localMax = -1, globalMax = INT32_MIN;
    for (long num : arr) {
        localMax = max(num, num + localMax);
        globalMax = max(localMax, globalMax); 
    }
    cout << globalMax;
    return 0;
}