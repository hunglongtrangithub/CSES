#include <iostream>
using namespace std;

int main() {
    long n, num;
    cin >> n;
    if (n > 3) {
        num = n - 1;
        while (num > 0) {
            cout << num << " ";
            num -= 2;
        }
        num = n;
        while (num > 0) {
            cout << num << " ";
            num -= 2;
        }
    } else if (n == 1) {
        cout << 1;
    } else { 
        cout << "NO SOLUTION";
    }
    return 0;
}