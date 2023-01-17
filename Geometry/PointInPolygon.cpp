#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct point {
    ll x, y;
};

int orientation(point p1, point p2, point p3) { 
    ll val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y); // cross product
    if (val == 0) {
        return 0; // colinear
    }
    return (val > 0) ? 1 : -1; // whether point (2) to the left or to the right of the line made by (1) and (3)
}

// check if point (2) lies on the line segment made by (1) and (3)
bool onSegment(point p1, point p2, point p3) {
    if (orientation(p1, p2, p3) == 0) {
        return p2.x <= max(p1.x, p3.x) && p2.x >= min(p1.x, p3.x) && p2.y <= max(p1.y, p3.y) && p2.y >= min(p1.y, p3.y);
    }
    return false;
}

string InsidePolygon(vector<point> P, int N, point p) {
    int counter = 0;
    for (int i = 0; i < N; i++) {
        point p1 = P[i];
        point p2 = P[(i + 1) % N];
        if (onSegment(p1, p, p2)) {
            return "BOUNDARY";
        }
        if (p1.x <= p.x && p.x < p2.x && orientation(p1, p, p2) > 0) {
            counter++;
        }
        if (p2.x <= p.x && p.x < p1.x && orientation(p2, p, p1) > 0) {
            counter++;
        }
    }
    if (counter % 2 == 0) {
        return "OUTSIDE";
    } else {
        return "INSIDE";
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<point> polygonPoints(n);
    for (int i = 0; i < n; i++) {
        cin >> polygonPoints[i].x >> polygonPoints[i].y;
    }
    for (int i = 0; i < m; i++) {
        point p;
        cin >> p.x >> p.y;
        cout << InsidePolygon(polygonPoints, n, p) << endl;
    }
}
