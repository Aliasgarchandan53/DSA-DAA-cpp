#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Coordinate
{
    int x, y;
};

struct LineSegment
{
    Coordinate start, end;
};

struct SweepEvent
{
    int x, y;
    bool isStart; 
    int segmentIndex;
    SweepEvent(int xVal, int yVal, bool isStartEvent, int index) : x(xVal), y(yVal), isStart(isStartEvent), segmentIndex(index) {}
    bool operator<(const SweepEvent &other) const
    {
        if (y == other.y)
            return x < other.x;
        return y < other.y;
    }
};

bool isOnSegment(Coordinate p, Coordinate q, Coordinate r)
{
    return q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y);
}

int orientation(Coordinate p, Coordinate q, Coordinate r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

bool doIntersect(LineSegment seg1, LineSegment seg2)
{
    Coordinate p1 = seg1.start, q1 = seg1.end, p2 = seg2.start, q2 = seg2.end;
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
        return true;
    if (o1 == 0 && isOnSegment(p1, p2, q1))
        return true;
    if (o2 == 0 && isOnSegment(p1, q2, q1))
        return true;
    if (o3 == 0 && isOnSegment(p2, p1, q2))
        return true;
    if (o4 == 0 && isOnSegment(p2, q1, q2))
        return true;
    return false;
}

set<SweepEvent>::iterator predecessor(set<SweepEvent> &eventSet, set<SweepEvent>::iterator current)
{
    return current == eventSet.begin() ? eventSet.end() : --current;
}

set<SweepEvent>::iterator successor(set<SweepEvent> &eventSet, set<SweepEvent>::iterator current)
{
    return ++current;
}

int countIntersections(vector<LineSegment> &segments)
{
    int numSegments = segments.size();
    vector<SweepEvent> events;
    set<SweepEvent> activeSegments;
    unordered_map<string, int> intersectionCounts;
	
    for (int i = 0; i < numSegments; ++i)
    {
        events.push_back(SweepEvent(segments[i].start.x, segments[i].start.y, true, i));
        events.push_back(SweepEvent(segments[i].end.x, segments[i].end.y, false, i));
    }
    sort(events.begin(), events.end());
    int totalIntersections = 0;
    for (auto &event : events)
    {
        int segmentIndex = event.segmentIndex;
        if (event.isStart)
        {
            for (auto it = activeSegments.begin(); it != activeSegments.end(); ++it)
            {
                if (doIntersect(segments[it->segmentIndex], segments[segmentIndex]))
                {
                    string segmentPairKey = to_string(min(it->segmentIndex, segmentIndex)) + "_" + to_string(max(it->segmentIndex, segmentIndex));
                    if (intersectionCounts.insert({segmentPairKey, 1}).second)
                    {
                        totalIntersections++;
                    }
                }
            }
            activeSegments.insert(event);
        }
        else
        {
            activeSegments.erase(SweepEvent(segments[segmentIndex].start.x, segments[segmentIndex].start.y, true, segmentIndex));
        }
    }
    cout << "Intersecting Line Segment Pairs:" << endl;
    for (auto &pair : intersectionCounts)
    {
        cout << "Segment Pair " << pair.first << endl;
    }
    return totalIntersections;
}

int main()
{
    cout << "Name:  DHRUV AGRAWAL" << endl;
    cout << "Registration Number: 22BCI0191" << endl;
    cout << "----------------------------" << endl;
    int numSegments;
    cout << "Enter the number of line segments: ";
    cin >> numSegments;
    vector<LineSegment> segments(numSegments);
    cout << "Enter the coordinates of each line segment (x1 y1 x2 y2 for each line):" << endl;
    for (int i = 0; i < numSegments; ++i)
    {
        cout<<endl<<"Line "<<i<<": ";
        cin >> segments[i].start.x >> segments[i].start.y >> segments[i].end.x >> segments[i].end.y;
        if (segments[i].start.x > segments[i].end.x)
        {
            swap(segments[i].start, segments[i].end);
        }
    }
    int numIntersections = countIntersections(segments);
    cout << "Number of intersection points: " << numIntersections << endl;

    return 0;
}