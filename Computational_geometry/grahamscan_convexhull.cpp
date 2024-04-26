/*Convex hull algorithm */

#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x,y;
};

Point p0; // global minimum 

//to find if point r is on left or right turn from points p and q
int orientation(Point p,Point q,Point r){
    int value = ((q.x-p.x)*(r.y-q.y)-(r.x-q.x)*(q.y-p.y));
    if(value==0) return 0;
    return (value>0 ?1 :2);
}

//custom comparator to compare polar angles of p1 and p2 wrt p0
bool compare(Point p1,Point p2){
    int o = orientation(p0,p1,p2);
    if(o==0){
        return ((p1.x+p1.y)<p2.x+p2.y);
    }
    return (o==2); //if it is a counter-clockwise turn 
}

//graham's scan algorithm for convex hull
vector<Point> convexHull(vector<Point> &points,vector<Point> &hull,int n){
    //finding global minimum or initial point :
    Point *min = &points[0];
    for(int i=0;i<n;i++){
        if(points[i].y < (*min).y||(points[i].y == (*min).y && points[i].x<(*min).x)){
            min=&points[i];
        }
    }
    swap(points[0],*min);
    p0=*min;

    //sort the points based upon polar angles
    sort(points.begin()+1,points.end(),compare);

    //initialise custom stack
    hull.push_back(points[0]);
    hull.push_back(points[1]);

    for(int i=2;i<n;i++){
        while(hull.size()>=2 && orientation(hull[hull.size()-2],hull[hull.size()-1],points[i])!=2)
            hull.pop_back();
        hull.push_back(points[i]);
    }
    return hull;
}

int main(){
    int n;
    cin>>n;
    vector<Point> points(n);
    for(int i=0;i<n;i++)
        cin>>points[i].x>>points[i].y;
    
    vector<Point> hull;
    convexHull(points,hull,n);
    //printing convex hull
    cout<<"Points lying on the convex hull are :\n";
    cout<<"[ ";
    for(auto it :hull){
        cout<<"("<<it.x<<","<<it.y<<") ";
    }
    cout<<"]\n";
    return 0;
}
