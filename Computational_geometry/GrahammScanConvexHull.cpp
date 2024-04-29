/* Graham scan algorithm for convex hull 
    1- orientation function, distanceSq function , comparison function,getNextToTop funcition, alforithm funcn, MAIN
    2- struct point
*/

#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
};

int orientation(Point p,Point q, Point r ){
 int val = (q.x-p.x)*(r.y-q.y)- (r.x-q.x)*(q.y-p.y);
 if(val==0)return 0;
 return (val>0?1:2);
}

int distSq(Point p, Point q){
    return (static_cast<int>(pow((q.x-p.x),2) + pow((q.y-p.y),2)));
}

Point p0;//global minimum

bool compare(Point p1,Point p2){
    int o = orientation(p0,p1,p2);
    if(o==0){
        return (distSq(p0,p1)<distSq(p0,p2));
    }
    return (o==2);
}

Point getNextToTop(stack<Point> &stk){
    Point p = stk.top();
    stk.pop();
    Point q= stk.top();
    stk.push(p);
    return q;
}

//Algorithm implemented :
void GrahamScanConvexHull(vector<Point> &points,int n){
    //find minimum :
    Point *min = &points[0];
    for(int i=1;i<n;i++){
        if(points[i].y<(*min).y || ( points[i].y<(*min).y && points[i].x<(*min).x))
            min=&points[i];
    }
    p0 = *min;
    swap(*min,points[0]);
    sort(points.begin()+1,points.end(),compare);
    //removing points with same orientation from array 
    int m=1;
    for(int i=1;i<n;i++){
        while(i<(n-1) && orientation(p0, points[i],points[i+1])==0)
            i++;
        points[m++]=points[i];
    }
    
    cout<<"Printing array :\n";
    for(auto it:points){
        cout<<"("<<it.x<<","<<it.y<<")\n";
    }

    //applying algorithm
    stack<Point> hull;
    hull.push(points[0]);
    hull.push(points[1]);

    for(int i=2;i<m;i++){
        while(hull.size() > 1  && orientation(getNextToTop(hull),hull.top(),points[i])!=2)
            hull.pop();
        hull.push(points[i]);
    }

    //print the hull:
    cout<<"Points included in the convex hull are : ";
    while(!hull.empty()){
        Point p =hull.top();
        cout<<"("<<p.x<<","<<p.y<<") ";
        hull.pop();
    }
}

int main(){
    int n;
    cin>>n;
    vector<Point> points(n);
    for(int i=0;i<n;i++){
        cin>>points[i].x>>points[i].y;
    }
    GrahamScanConvexHull(points,n);
    return 0;
}