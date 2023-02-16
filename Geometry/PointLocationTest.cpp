#include <iostream>
using namespace std;
 
int main() {
    long t;
    cin >> t;
    while (t--) {
        long x1, y1, x2, y2, x3, y3;
        cin >> x1;
        cin >> y1;
        cin >> x2;
        cin >> y2;
        cin >> x3;
        cin >> y3;
        long check = (x2 - x1) * (y3 - y2) - (x3 - x2) * (y2 - y1); // cross product
        if (check > 0) {
            cout << "LEFT" << endl;
        }
        if (check == 0) {
            cout << "TOUCH" << endl;
        }
        if (check < 0) {
            cout << "RIGHT" << endl;
        }
    }
}