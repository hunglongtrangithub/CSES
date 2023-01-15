#include <iostream>
using namespace std;
#define ll long long;

string s;
bool visited[7][7];
int ans;

// returns true if (x, y) is a valid coordinate and has not been visited
bool legit(int x, int y) {
    return 0 <= x && x < 7 && 0 <= y && y < 7 && !visited[x][y];
}

// Depth first search. x and y are the current coordinates, a is the index of the current character in s
void dfs(int x, int y, int a = 0) {
    if (x == 0 && y == 6) {
        if (a == 48) {
            ans++;
        }
        return;
    }
    if (s[a] == '?' || s[a] == 'L') {
        if (x > 0 && !visited[x - 1][y]) {
            if (!(!legit(x - 2, y) && legit(x - 1, y - 1) && legit(x - 1, y + 1))) {
                dfs(x - 1, y, a + 1);
            }
        }
    }
    if (s[a] == '?' || s[a] == 'R') {
        if (x < 6 && !visited[x + 1][y]) {
            if (!(!legit(x + 2, y) && legit(x + 1, y - 1) && legit(x + 1, y + 1))) {
                dfs(x + 1, y, a + 1);
            }
        }
    }
    if (s[a] == '?' || s[a] == 'U') {
        if (y > 0 && !visited[x][y - 1]) {
            if (!(!legit(x, y - 2) && legit(x - 1, y - 1) && legit(x + 1, y - 1))) {
                dfs(x, y - 1, a + 1);
            }
        }
    }
    if (s[a] == '?' || s[a] == 'D') {
        if (y < 6 && !visited[x][y + 1]) {
            if (!(!legit(x, y + 2) && legit(x + 1, y + 1) && legit(x - 1, y + 1))) {
                dfs(x, y + 1, a + 1);
            }
        }
    }
    visited[x][y] = 0;
}

int main() {
    cin >> s;
    dfs(0, 0);
    cout << ans << endl;
}