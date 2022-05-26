#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Point {
private:
    
public:
    int x, y;

    Point(int x, int y): x(x), y(y) {}

    void print() {
        cout << x << " " << y << '\n';
    }
};

int N;
vector<Point> PointVec;

void prosetting();
void input();
void printVec() {
    for (Point& p : PointVec) {
        p.print();
    }
}

bool comp(Point a, Point b) {
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int main() {
    prosetting();
    input();

    //printVec();

    sort(PointVec.begin(), PointVec.end(), comp);

    printVec();
}

void prosetting() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
}

void input() {
    cin >> N;
    for (int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        Point newPoint = Point(x, y);
        PointVec.push_back(newPoint);
    }
}