/*Sweeping line algorithm */
#include <bits/stdc++.h>
using namespace std;

// Structure to represent a point
struct Point {
    int x, y;

    // Overload the equality operator to compare points
    bool operator==(Point& other) {
        return x == other.x && y == other.y;
    }
};

// Structure to represent a line segment
struct LineSegment {
    Point start, end;
};

// Structure to represent an event point
struct Event {
    Point point;
    int segmentIndex; // Index of the line segment associated with this event
    bool isStart; // Flag to indicate whether it's a start point of a line segment
};

// Comparator for sorting line segments based on their starting y-coordinate
struct SegmentComparator {
    bool operator()(LineSegment& a, LineSegment& b){
        return a.start.y < b.start.y;
    }
};

bool compareEvents(Event &a,Event &b){
    return a.point.x < b.point.x;
}

struct pqComparator{
    bool operator()(Event &a,Event &b){
     return a.point.y > b.point.y;
    }
};

// Function to check if a point q lies on the line segment pr
bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

// Function to find the orientation of ordered triplet (p, q, r)
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0; // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// Function to check if two line segments p and q intersect
bool doIntersect(LineSegment p, LineSegment q, Point& intersection) {
    int o1 = orientation(p.start, p.end, q.start);
    int o2 = orientation(p.start, p.end, q.end);
    int o3 = orientation(q.start, q.end, p.start);
    int o4 = orientation(q.start, q.end, p.end);

    // General case
    if (o1 != o2 && o3 != o4) {
        // Compute intersection point
        int x1 = p.start.x, y1 = p.start.y;
        int x2 = p.end.x, y2 = p.end.y;
        int x3 = q.start.x, y3 = q.start.y;
        int x4 = q.end.x, y4 = q.end.y;

        int denom = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
        if (denom == 0) return false; // Lines are parallel or coincident

        int t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denom;
        int u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denom;
        if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
            intersection.x = x1 + t * (x2 - x1);
            intersection.y = y1 + t * (y2 - y1);
            return true;
        }
    }

    return false;
}

// Function to find intersections using the sweeping line technique
void findIntersections(vector<pair<Point, Point>> lines) {
    vector<Event> events;

    // Create events for start and end points of each line segment
    for (size_t i = 0; i < lines.size(); ++i) {
        events.push_back({lines[i].first, int(i), true});
        events.push_back({lines[i].second, int(i), false});
    }

    // Sort events based on their x-coordinate
    sort(events.begin(), events.end(), compareEvents ); 

    // Priority queue to store active segments based on their ending y-coordinate
    priority_queue<Event, vector<Event>, pqComparator> pq;

    // Traverse through all events
    for (auto event : events) {
        if (event.isStart) {
            // Check for intersections with active segments
            while (!pq.empty()) {
                Event activeEvent = pq.top();
                pq.pop();
                auto segment = lines[activeEvent.segmentIndex];
                if (event.segmentIndex != activeEvent.segmentIndex) {
                    Point intersection;
                    if (doIntersect({event.point, lines[event.segmentIndex].second}, {segment.first, segment.second}, intersection)) {
                        cout << "Intersection at (" << intersection.x << ", " << intersection.y << ")\n";
                        cout << "Line segments involved:\n";
                        cout << "Segment 1: (" << event.point.x << ", " << event.point.y << ") to (" << lines[event.segmentIndex].second.x << ", " << lines[event.segmentIndex].second.y << ")\n";
                        cout << "Segment 2: (" << segment.first.x << ", " << segment.first.y << ") to (" << segment.second.x << ", " << segment.second.y << ")\n";
                    } 
                }
            }
            pq.push(event); // Add the start event to the priority queue
        } else {
            // Remove the end event from the priority queue
            priority_queue<Event, vector<Event>, pqComparator> tempPq;
            while (!pq.empty()) {
                if (!(pq.top().segmentIndex == event.segmentIndex && pq.top().isStart)) {
                    tempPq.push(pq.top());
                }
                pq.pop();
            }
            swap(pq, tempPq);
        }
    }
}

int main() {
    // Example line segments
    int n;
    cin>>n;
    vector<pair<Point, Point>> test_case(n); 
    for(int i=0;i<n;i++){
        cin>>test_case[i].first.x>>test_case[i].first.y>>test_case[i].second.x>>test_case[i].second.y;
    }
    findIntersections(test_case);
    return 0;
}