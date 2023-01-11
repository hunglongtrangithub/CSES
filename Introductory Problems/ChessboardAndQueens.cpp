#include <iostream>
using namespace std;

int number_of_ways = 0;
bool col[8]; // represents the columns, x = constant
bool diag1[2 * 8 - 1]; // represents the diagonals from top left to bottom right, x + y = constant
bool diag2[2 * 8 - 1]; // represents the diagonals from top right to bottom left, x - y = constant 
bool reserves[8][8]; // the chessboard
// backtracking 
void search(int y = 0) {
    if (y == 8) {
        number_of_ways++;
    } else {    
        for (int x = 0; x < 8; x++) {
            if (reserves[y][x] && col[x] == 0 && diag1[x + y] == 0 && diag2[x - y + 8 - 1] == 0) {
                col[x] = diag1[x + y] = diag2[x - y + 7] = 1;
                search(y + 1);
                col[x] = diag1[x + y] = diag2[x - y + 7] = 0;
                // x - y + 7 > 0 for all x and y in the range [0, 7]
            }
        }
    }
}

int main() {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            char input;
            cin >> input;
            reserves[y][x] = (input == '*') ? 0 : 1;
        }
    }
    search();
    cout << number_of_ways;
}
