#include <iostream>
using namespace std;

int number_of_ways = 0;
bool col[8]; // represents the columns, x = constant (0 <= constant <= 7)
bool diag1[15]; // represents the diagonals from top left to bottom right, x + y = constant (0 <= x + y <= 14)
bool diag2[15]; // represents the diagonals from top right to bottom left, x - y = constant (-7 <= x - y <= 7)
bool reserves[8][8]; // the chessboard 

// backtracking 
void search(int y = 0) {
    if (y == 8) {
        number_of_ways++;
    } else {    
        for (int x = 0; x < 8; x++) {
            if (reserves[y][x] && col[x] == 0 && diag1[x + y] == 0 && diag2[x - y + 7] == 0) {
                col[x] = diag1[x + y] = diag2[x - y + 7] = 1;
                search(y + 1);
                col[x] = diag1[x + y] = diag2[x - y + 7] = 0;
                // 0 <= x - y + 7 <= 14 for all x and y in the range 0 <= x, y <= 7
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
