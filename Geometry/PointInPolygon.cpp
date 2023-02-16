#include <iostream>
#include <vector>
using namespace std;

struct point {
    long x, y;
};

int orientation(point p1, point p2, point p3) { 
    // cross product of vectors (1)(2) and (2)(3)
    long val = (p2.x - p1.x) * (p3.y - p2.y) - (p2.y - p1.y) * (p3.x - p2.x); 
    if (val == 0) {
        return 0; // colinear
    }
    return (val < 0) ? -1 : 1; // whether point (2) is to the left (-1) or to the right (1) of vector (1)(3)
}

// check if point (2) lies on the line segment made by (1) and (3)
bool onSegment(point p1, point p2, point p3) {
    if (orientation(p1, p2, p3) == 0) {
        return p2.x <= max(p1.x, p3.x) && p2.x >= min(p1.x, p3.x) && p2.y <= max(p1.y, p3.y) && p2.y >= min(p1.y, p3.y);
    }
    return false;
}

/* Ray casting algorithm: 
Cast a horizontal "ray" from the point in question to the right, and count 
the number of times the ray intersects with the edges of the polygon. 
If the number of intersections is odd, the point is inside the polygon. 
If the number of intersections is even, the point is outside the polygon. 
*/
string insidePolygon(vector<point> P, int N, point p) {
    int counter = 0;
    for (int i = 0; i < N; i++) {
        point p1 = P[i];
        point p2 = P[(i + 1) % N];
        // first check if p lies on the line segment made by p1 and p2
        if (onSegment(p1, p, p2)) {
            return "BOUNDARY";
        }
        /* This is where onSegment(p1, p, p2) == false. 
        If p1.y == p2.y != p.y, ignore and move on the next segment. If p1.y == p2.y == p.y, then either 
        (1) p.x > min(p1.x, p2.x) or (2) p.x < max(p1.x, p2.x). If (1), ignore and move on. If (2), we also 
        ignore because the segment does not contribute to the count. Thus, we only consider when p1.y != p2.y. */
        if (p1.y <= p.y && p.y < p2.y && orientation(p1, p, p2) < 0) {
            counter++;
        }
        if (p2.y <= p.y && p.y < p1.y && orientation(p2, p, p1) < 0) {
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
    long n, m;
    cin >> n >> m;
    vector<point> polygon_points(n);
    for (int i = 0; i < n; i++) {
        cin >> polygon_points[i].x >> polygon_points[i].y;
    }
    for (int i = 0; i < m; i++) {
        point p;
        cin >> p.x >> p.y;
        cout << insidePolygon(polygon_points, n, p) << endl;
    }
}
