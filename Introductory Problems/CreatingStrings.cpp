#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> all_permutations(string s) {
    set<string> ans;
    if (s.size() == 1) { // base case
        ans.insert(s);
        return ans;
    }
    for (long i = 0; i < long(s.size()); i++) {
        string temp = s;
        temp.erase(temp.begin() + i); // remove the i-th character
        // temp_ans is the set of all permutations of the string without the i-th character
        set<string> temp_ans = all_permutations(temp); 
        // ans is the set of all strings in temp_ans with i-th character added to the beginning of each string 
        for (string str : temp_ans) {
            ans.insert(s.at(i) + str); 
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
    return 0;
}