#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

set<string> all_permutations(string s) {
    set<string> ans;
    if (s.size() == 1) {
        ans.insert(s);
        return ans;
    }
    char letter = s.back(); // last letter of s
    // iterate through all permutations of s without the last letter
    for (string str : all_permutations(s.substr(0,s.size() - 1))) {
        for (int i = 0; i < int(str.size() + 1); i++) {
            // insert the letter at position i in all of the permutations of str
            ans.insert(str.substr(0, i) + letter + str.substr(i, str.size()));
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << all_permutations(s).size() << endl;
    for (string str : all_permutations(s)) {
        cout << str << endl;
    }
}