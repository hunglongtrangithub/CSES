#include <iostream>
#include <vector>
using namespace std;
#define ll long long 
int q;
ll k;
string digit;
vector< vector<ll> > pivot(19,vector<ll>(2,1));
int main() {
    for (int n=1; n<19; n++) {
        pivot[n][0]=pivot[n-1][0]+9*pivot[n-1][1]*n;
        pivot[n][1]=pivot[n-1][1]*10;
    }
    cin >> q;
    while (q--) {
        cin >> k;
        int i=1;
        while (!(pivot[i-1][0]<=k&&k<pivot[i][0])) i++;
        k=k-pivot[i-1][0]+1;
        ll num=pivot[i-1][1]+k/i;
        if (k%i) {
            digit=to_string(num)[k%i-1];
        } else {
            digit=to_string(num-1)[to_string(num-1).size()-1];
        }
        cout << digit << endl;
    }
}