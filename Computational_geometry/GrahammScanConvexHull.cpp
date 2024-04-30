/*Graham Scan algorithm :
    structure point 
    functions -  orientation, distancesqr, comparison, getnexttotop,grscam algo, main
*/

#include <bits/stdc++.h>
using namespace std;

struct point{
    int x,y;
};

point p0; //global minimum

int orientation(point p,point q, point r){
    int val = (q.x-p.x)*(r.y-q.y)-(q.y-p.y)*(r.x-q.x);
    if(val==0)return 0;
    return (val>0?1:2);
}

int distSqr(point p,point q){
    return int(pow(q.x-p.x,2)+pow(q.y-p.y,2));
}

point getNextToTop(stack<point> &stk){
    point p0=stk.top();
    stk.pop();
    point p1=stk.top();
    stk.push(p0);
    return p1;
}

bool comparison(point &p1,point &p2){
    int o = orientation(p0,p1,p2);
    if(o==0)
        return (distSqr(p0,p1)<distSqr(p0,p2));
    return (o==2);
}

void GrahamScan(vector<point> &points,int n){
    //finding global minimum
    point *min = &points[0];
    for(int i=1;i<n;i++){
        if(points[i].y<(*min).y || (points[i].y==(*min).y && points[i].x<(*min).x )){
            min=&points[i];
        }
    }
    swap(*min,points[0]);
    p0=*min;
    sort(points.begin()+1,points.end(),comparison);


    //scanning the points.
    stack<point> hull;
    hull.push(points[0]);
    hull.push(points[1]);

    for(int i=2;i<n;i++){
        while(hull.size()>1 && orientation(getNextToTop(hull),hull.top(),points[i])!=2)
            hull.pop();
        hull.push(points[i]);
    } 

    cout<<"points included in the convex hull are :\n";
    while(!hull.empty()){
        point p=hull.top();
        cout<<"("<<p.x<<","<<p.y<<") ";
        hull.pop();
    }
}

int main() {
    int n;
    cin>>n;
    vector<point> points(n);
    for(int i=0;i<n;i++)
        cin>>points[i].x>>points[i].y;
    GrahamScan(points,n); 
    return 0;
}
