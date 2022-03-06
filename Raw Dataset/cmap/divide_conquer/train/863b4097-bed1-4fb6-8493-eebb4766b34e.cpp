#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

ifstream fin("cmap.in");
ofstream fout("cmap.out");

struct Point {
    int x, y;
};

vector <Point> points;

inline bool cmp_byXY(Point a, Point b) {
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

inline bool cmp_byY(Point a, Point b) {
    return a.y < b.y;
}

inline double getDistance(Point& a, Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double d = sqrt(dx * dx + dy * dy);

    return d;
}

double bruteForce(int left, int right, vector <Point>& points) {
    double delta = getDistance(points[left], points[left + 1]);
    for(int i = left; i < right; ++i) {
        for(int j = i + 1; j < right; ++j) {
            double tmp = getDistance(points[i], points[j]);
            if(tmp < delta) {
                delta = tmp;
            }
        }
    }

    return delta;
}

void splitY(vector <Point>& points, vector <Point>& yL, vector <Point>& yR, Point threshold) {
    for(int i = 0; i < (int) points.size(); ++i) {
        if(points[i].x < threshold.x || (points[i].x == threshold.x && points[i].y <= threshold.y)) {
            yL.push_back(points[i]);
        }else {
            yR.push_back(points[i]);
        }
    }
}

double closestPair(int left, int right, vector <Point>& points, vector <Point>& pointsByY) {
    if(right - left <= 3) {
        return bruteForce(left, right, points);
    }
    else {
        int middle = (left + right + 1) / 2;
        vector <Point> yL;
        vector <Point> yR;

        splitY(pointsByY, yL, yR, points[middle - 1]);

        double dL = closestPair(left, middle, points, yL);
        double dR = closestPair(middle, right, points, yR);
        double d = dL;
        if(dR < d) {
            d = dR;
        }

        for(int i = 0; i < (int) pointsByY.size(); i++) {
            for(int j = i + 1; j < min(i + 6, (int) pointsByY.size()); j++) {
                double tmp = getDistance(pointsByY[i], pointsByY[j]);
                if(tmp < d) {
                    d = tmp;
                }
            }
        }

        return d;
    }
}

int main() {
    int n;
    fin >> n;
    for(int i = 0; i < n; ++i) {
        Point tmp;
        fin >> tmp.x >> tmp.y;

        points.push_back(tmp);

    }

    vector <Point> pointsByY = points;

    sort(points.begin(), points.end(), cmp_byXY);
    sort(pointsByY.begin(), pointsByY.end(), cmp_byY);

    fout << fixed << setprecision(7) << closestPair(0, n , points, pointsByY) << "\n";

    return 0;
}
