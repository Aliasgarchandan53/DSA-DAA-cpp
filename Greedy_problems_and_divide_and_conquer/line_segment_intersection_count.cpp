#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; 
    return (val > 0) ? 1 : 2;
}

bool comparePts(pair<Point,Point> &p,pair<Point,Point> &q){
    return (p.first.x < q.first.x);
}

int doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4) return 1;
    if (o1 == 0 && o1 == o2 && o1 == o3 && o1 == o4) return 1;
    return 0; 
}

int countIntersections(vector<pair<Point,Point>> &p, int n) {
    sort(p.begin(),p.end(),comparePts);
    int count = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (doIntersect(p[i].first, p[i].second, p[j].first, p[j].second)) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<pair<Point,Point>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first.x >> p[i].first.y;
        cin >>p[i].second.x >> p[i].second.y;
    }
    int intersections = countIntersections(p, n);
    cout << "Number of intersections: " << intersections << endl;
    return 0;
}
