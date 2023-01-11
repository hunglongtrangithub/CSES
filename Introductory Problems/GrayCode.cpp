#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;
    string arr[n]; // arr[i] is a string that contains the i'th bit of all of the bit strings in the Gray code
    // fill the array
    for (int a = 0; a < n; a++) {
        // fill the a-th row of the array
        for (int b = 0; b < int(pow(2, n - a)); b++) {
            for (int c = 0; c < int(pow(2, a)); c++) {
                if (b % 4 == 0 || b % 4 == 3) 
                    arr[a] += '0';
                else 
                    arr[a] += '1';
            }
        }
    }
    for (int i = 0; i < int(pow(2, n)); i++) {
        string s; 
        // print the ith row of the array
        for (int j = 0; j < n; j++) 
            s += arr[j][i];
        cout << s << endl;
    }
}