#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#define ll long long
int main() {
    int n;
    cin >> n;
    string arr[n];
    for (int a=0; a<n; ++a) {
        for (int b=0; b<int(pow(2,n-a)); ++b) {
            for (int c=0; c<int(pow(2,a)); ++c) {
                if (b%4==0||b%4==3) arr[a]+='0';
                else arr[a]+='1';
            }
        }
    }
    for (int i=0; i<int(pow(2,n)); ++i) {
        string s;
        for (int j=0; j<n; ++j) s+=arr[j][i];
        cout << s << endl;
    }
}