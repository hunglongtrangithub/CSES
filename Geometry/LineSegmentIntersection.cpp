#include <iostream>
using namespace std;
#define ll long long

int orientation(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) { 
    ll val = (y2-y1)*(x3-x2) - (x2-x1)*(y3-y2); // cross product
    if (val==0) {
        return 0; // colinear
    }
    return (val>0)?1:2; // clock or counterclock wise
}
bool onSegment(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    // this function is only valid when three points are colinear
    if (x2<=max(x1,x3) && x2>=min(x1,x3) && y2<=max(y1,y3) && y2>=min(y1,y3)) {
        return true;
    }
    return false;
}
int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        if ((x1==x3&&y1==y3) 
            || (x1==x4&&y1==y4) 
            || (x2==x3&&y2==y3) 
            || (x2==x4&&y2==y4)) {
            cout<<"YES"<<endl;
        } else if (orientation(x1,y1,x3,y3,x2,y2)==0
                &&orientation(x1,y1,x4,y4,x2,y2)==0) {
            if (onSegment(x1,y1,x3,y3,x2,y2) 
            || onSegment(x1,y1,x4,y4,x2,y2) 
            || onSegment(x3,y3,x1,y1,x4,y4) 
            || onSegment(x3,y3,x2,y2,x4,y4)) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        } else if (orientation(x1,y1,x3,y3,x2,y2)!=orientation(x1,y1,x4,y4,x2,y2) 
            && orientation(x3,y3,x1,y1,x4,y4)!=orientation(x3,y3,x2,y2,x4,y4)) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}