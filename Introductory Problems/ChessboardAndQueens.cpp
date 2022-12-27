#include <iostream>
#include <cmath>
using namespace std;
int c=0;
bool col[8];
bool diag1[2*8-1];
bool diag2[2*8-1];
bool reserves[8][8];
void search(int y=0) {
    if (y==8) {
        c++;
    } else {    
        for (int x=0; x<8; ++x) {
            if (reserves[y][x]&&col[x]==0&&diag1[x+y]==0&&diag2[x-y+8-1]==0) {
                col[x]=diag1[x+y]=diag2[x-y+8-1]=1;
                search(y+1);
                col[x]=diag1[x+y]=diag2[x-y+8-1]=0;
            }
        }
    }
}
int main() {
    for (int y=0; y<8; ++y) {
        for (int x=0; x<8; ++x) {
            char input;
            cin >> input;
            reserves[y][x] = (input=='*') ? 0 : 1;
        }
    }
    search();
    cout << c;
}
