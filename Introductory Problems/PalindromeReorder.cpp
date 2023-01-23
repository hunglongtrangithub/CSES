#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    long ch[26] = {0}, count = 0; // ch[i] is the number of characters that are i + 'A'
    // Count the number of each character
    for (char c : s) {
        ch[c - 'A'] += 1;
    }
    // Count the number of characters that appear an odd number of times
    for (long i = 0; i < 26; i++) {
        count += ch[i] % 2;
    }
    if (count > 1) {
        cout << "NO SOLUTION";
    } else {
        string result = "";
        for (long i = 0; i < 26; i++) {
            if (ch[i] % 2 == 0) {
                for (long j = 0; j < ch[i] / 2; j++) {
                    result += (i + 'A'); 
                }
            } 
        }
        for (long i = 0; i < 26; i++) {
            if (ch[i] % 2 != 0) {
                for (long j = 0; j < ch[i]; j++) {
                    result += (i + 'A');
                }
            }
        }
        for (long i = 25; i >= 0; i--) {
            if (ch[i] % 2 == 0){
                for (long j = 0; j < ch[i] / 2; j++) {
                     result += (i + 'A');
                }
            }
        }
        cout << result;
    }
    return 0;
}