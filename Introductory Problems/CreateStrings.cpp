#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
set<string> all_permutations(string s) {
    set<string> ans;
    if (s.size()==1) {
        ans.insert(s);
        return ans;
    }
    char element=s[s.size()-1];
    for (string i : all_permutations(s.substr(0,s.size()-1))) {
        for (int j=0; j<i.size()+1; ++j) {
            string st=i.substr(0,j)+element+i.substr(j,i.size());
            ans.insert(st);
        }
    }
    return ans;
}
int main() {
    string s;
    cin >> s;
    set<string> res=all_permutations(s);
    cout << res.size() << endl;
    vector<string> v(res.begin(), res.end());
    sort(v.begin(), v.end());
    for (string i : v) cout << i << endl;
}