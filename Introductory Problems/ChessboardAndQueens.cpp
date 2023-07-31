#include <iostream>
#include <vector>
using namespace std;

long number_of_ways = 0;
vector<bool> col(8, false); // represents the columns, x = constant (0 <= constant <= 7). false = unoccupied, true = occupied
vector<bool> diag1(15, false); // represents the diagonals from top left to bottom right, where x + y = constant (0 <= x + y <= 14). false = unoccupied, true = occupied
vector<bool> diag2(15, false); // represents the diagonals from top right to bottom left, where x - y + 7 = constant (0 <= x - y + 7 <= 14). false = unoccupied, true = occupied
vector<vector<bool>> reserves(8, vector<bool>(8)); // the chessboard 

// backtracking 
void search(long y=0) {
    if (y == 8) {
        number_of_ways++;
    } else {    
        for (long x = 0; x < 8; x++) {
            if (reserves[y][x] && !col[x] && !diag1[x + y] && !diag2[x - y + 7]) {
                col[x] = diag1[x + y] = diag2[x - y + 7] = true; // mark the column, diagonal1, and diagonal2 as occupied
                search(y + 1);
                col[x] = diag1[x + y] = diag2[x - y + 7] = false; // unmark the column, diagonal1, and diagonal2
            }
        }
    }
}

int main() {
    for (long y = 0; y < 8; y++) {
        for (long x = 0; x < 8; x++) {
            char input;
            cin >> input;
            reserves[y][x] = (input == '*') ? false : true;
        }
    }
    search();
    cout << number_of_ways;
    return 0;
}
