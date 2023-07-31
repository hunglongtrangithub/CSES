#include <iostream>
using namespace std;

struct point {
    long x, y;
};

long orientation(point p1, point p2, point p3) { 
    // cross product of vectors (1)(2) and (2)(3)
    long val = (p2.x - p1.x) * (p3.y - p2.y) - (p2.y - p1.y) * (p3.x - p2.x); 
    if (val == 0) {
        return 0; // colinear
    }
    return (val < 0) ? -1 : 1; // whether point (2) to the left (-1) or to the right (1) of vector (1)(3)
}

// check if point (2) lies on the line segment made by (1) and (3)
bool onSegment(point p1, point p2, point p3) {
    if (orientation(p1, p2, p3) == 0) {
        return p2.x <= max(p1.x, p3.x) && p2.x >= min(p1.x, p3.x) && p2.y <= max(p1.y, p3.y) && p2.y >= min(p1.y, p3.y);
    } 
    return false;
}

int main() {
    long t;
    cin >> t;
    while (t--) {
        point p1, p2, p3, p4;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
        // check if any point is same
        if ((p1.x == p3.x && p1.y == p3.y) 
            || (p1.x == p4.x && p1.y == p4.y) 
            || (p2.x == p3.x && p2.y == p3.y) 
            || (p2.x == p4.x && p2.y == p4.y)) { 
            cout << "YES" << endl;
        // check if along 4 points are colinear
        } else if (orientation(p1, p3, p2) == 0 &&orientation(p1, p4, p2) == 0) { 
            // check if any end point of a segment lies on the other segment
            if (onSegment(p1, p3, p2) || onSegment(p1, p4, p2) || onSegment(p3, p1, p4) || onSegment(p3, p2, p4)) { 
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if (orientation(p1, p3, p2) != orientation(p1, p4, p2) 
            && orientation(p3, p1, p4) != orientation(p3, p2, p4)) {
            /* 
            the two segments intersect only when (1) and (2) are on opposite sides of the line made by (3) and (4) 
            and (3) and (4) are on opposite sides of the line made by (1) and (2) 
            */
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}