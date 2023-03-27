#include <iostream>
using namespace std;

int main() {
    long n;
    cin >> n;
    /*
    The expression used to calculate the number of ways is as follows:
    ((k * k) * ((k * k) - 1)) / 2 - 4 * (k - 1) * (k - 2)
    Here, k represents the size of the chessboard, which is an integer input by the user.

    The first part of the expression calculates the total number of ways to place two knights on an n x n chessboard 
    without any restrictions, which is C(k^2, 2) = (k^2 * (k^2 - 1)) / 2. 

    The second part of the expression 4 * (k - 1) * (k - 2) calculates the number of attacking positions. 
    This is done as follows:
    1. The knights are in attacking position if they are on the two ends of a diagonal of a 2 x 3 rectangle.
    2. There are 2 * (k - 1) * (k - 2) such rectangles on the board (vertical and horizontal),
    3. and each rectangle has 2 diagonals (which means 2 ways of putting the knights in attacking positions), 
    4. so there are 4 * (k - 1) * (k - 2) attacking positions.
    
    Subtracting the number of attacking positions from the total number of ways to place two knights on the board 
    gives the number of non-attacking positions. 
    */
    for (long k = 1; k <= n; k++) {
        long ans = ((k * k) * ((k * k) - 1)) / 2 - 4 * (k - 1) * (k - 2);
        cout << ans << endl;
    }
    return 0;
}
