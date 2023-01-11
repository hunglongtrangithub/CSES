#include <iostream>
using namespace std;
#define ll long long

int main() {
    string s;
    cin >> s;
    ll ch[26] = {0}, count = 0; // ch[i] is the number of characters that are i + 'A'
    // Count the number of each character
    for (char c : s) 
        ch[c - 'A'] += 1;
    // Count the number of characters that appear an odd number of times
    for (int i = 0; i < 26; i++) 
        count += ch[i] % 2;
    if (count > 1) {
        cout << "NO SOLUTION";
    } else {
        string result = "";
        for (int i = 0; i < 26; i++) {
            if(ch[i] % 2 == 0) {
                for(int j = 0; j < ch[i] / 2; j++) 
                    result += (i + 'A'); 
            } 
        }
        for (int i = 0; i < 26; i++) {
            if(ch[i] % 2 != 0) {
                for(int j = 0; j < ch[i]; j++) 
                    result += (i + 'A');
            }
        }
        for (int i = 25; i >= 0; i--) {
            if(ch[i] % 2 == 0){
                for(int j = 0; j < ch[i] / 2; j++) 
                    result+=(i + 'A');
            }
        }
        cout << result << endl;
    }
}