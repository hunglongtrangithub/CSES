#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> all_permutations(string s) {
    set<string> ans;
    if (s.size() == 1) {
        ans.insert(s);
        return ans;
    }
    for (long i = 0; i < long(s.size()); i++) {
        string temp = s;
        temp.erase(temp.begin() + i);
        set<string> temp_ans = all_permutations(temp);
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