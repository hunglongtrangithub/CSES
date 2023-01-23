#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    long n;
    cin >> n;
    string arr[n]; // arr[i] is a string that contains the i'th bit of all of the bit strings in the Gray code
    // fill the array
    for (long a = 0; a < n; a++) {
        // fill the a-th row of the array
        for (long b = 0; b < long(pow(2, n - a)); b++) {
            for (long c = 0; c < long(pow(2, a)); c++) {
                if (b % 4 == 0 || b % 4 == 3) {
                    arr[a] += '0';
                } else { 
                    arr[a] += '1'; 
                }
            }
        }
    }
    for (long i = 0; i < long(pow(2, n)); i++) {
        string s; 
        // prlong the ith row of the array
        for (long j = 0; j < n; j++) {
            s += arr[j][i];
        }
        cout << s << endl;
    }
    return 0;
}