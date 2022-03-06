#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

struct Point {
    long long x, y;
    friend bool operator<(const Point &p1, const Point &p2);
    friend struct byY;
    struct byY {
        bool operator() (Point const &p1, Point const &p2) {
            return p1.y > p2.y;
        }
    };
};

bool operator<(const Point &p1, const Point &p2) {
    return p1.x < p2.x;
}

vector<Point> read(long long &n) {
    ifstream fin("cmap.in");
    vector<Point> points;
    fin >> n;
    Point aux;
    aux.x = LLONG_MAX;
    aux.y = LLONG_MAX;
    points.push_back(aux);
    for (int i = 1; i <= n; i++) {
        fin >> aux.x >> aux.y;
        points.push_back(aux);
    }
    fin.close();
    return points;
}

void write(int n, vector<Point> points) {
    for (int i = 1; i <= n; i++) {
        cout << points[i].x << " " << points[i].y << "\n";
    }
}

double distance(Point A, Point B) {
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

double minDistanceBetweenNPoints(int li, int ls, vector<Point> &points) {
    double minDist = LLONG_MAX;

    for (int i = li; i < ls; i++) {
        for (int j = i + 1; j <= ls; j++) {
            if (minDist > distance(points[i], points[j])) {
                minDist = distance(points[i], points[j]);
            }
        }
    }

    return minDist;
}

double divide(int li, int ls, vector<Point> &points) {
    if (ls - li < 3) {
        return minDistanceBetweenNPoints(li, ls, points);
    }
    int mid = (li + ls)/2;
    double dl = divide(li, mid, points);
    double dr = divide(mid + 1, ls, points);
    double dmin = min(dl, dr);


    vector<Point> strip;
    Point aux;
    aux.x = INT_MAX;
    aux.y = INT_MAX;
    strip.push_back(aux);
    for (int i = li; i <= ls; i++) {
        if (i != mid && abs(points[mid].x - points[i].x) <= dmin) {
            strip.push_back(points[i]);
        }
    }
    sort(strip.begin() + 1, strip.end(), Point::byY());

    for (int i = 1; i < strip.size() - 1; i++) {
        for (int j = i + 1; j < i + 8 && j < strip.size(); j++) {
            if (distance(strip[i], strip[j]) >= dmin) {
                break;
            } else if (distance(strip[i], strip[j]) < dmin) {
                dmin = distance(strip[i], strip[j]);
            }
        }
    }

    return dmin;
}

int main() {
    long long n;
    vector<Point> points;
    points = read(n);
    sort(points.begin() + 1, points.end());

    ofstream fout("cmap.out");
    fout << fixed << setprecision(6) << divide(1, n, points);
    return 0;
}
