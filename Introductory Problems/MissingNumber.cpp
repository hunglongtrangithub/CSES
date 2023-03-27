#include <iostream>
using namespace std;

int main() {
    long n, sum = 0;
    cin >> n;
    for (int i = 1; i < n; i++) {
        long num;
        cin >> num;
        sum += num;
    }
    // the missing number is the sum of all numbers from 1 to n minus the sum of the n - 1 numbers given
    cout << n * (n + 1) / 2 - sum;
    return 0;
}