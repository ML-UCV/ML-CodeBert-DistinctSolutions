#include <fstream>
#include <vector>#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;



const int EPS = 0.00000001;



struct Point {

    int x, y;

};



int n;

vector <Point> points;



inline int double_cmp(double& a, double& b) {

    if(a - b < -EPS) {

        return -1;

    }

    else if(a - b < EPS) {

        return 0;

    }

    else {

        return 1;

    }

}



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



double naiveClosestPair(int left, int right, vector <Point>& points) {

    double delta = getDistance(points[left], points[left + 1]);

    for(int i = left; i < right; ++i) {

        for(int j = i + 1; j < right; ++j) {

            double tmp = getDistance(points[i], points[j]);

            if(double_cmp(delta, tmp) < 0) {

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

        }

        else {

            yR.push_back(points[i]);

        }

    }

}



double closestPair(int left, int right, vector <Point>& points, vector <Point>& pointsByY) {

    if(right - left <= 3) {

        return naiveClosestPair(left, right, points);

    }

    else {

        int m = (left + right + 1) / 2;

        vector <Point> yL;

        vector <Point> yR;



        splitY(pointsByY, yL, yR, points[m - 1]);



        double dL = closestPair(left, m, points, yL);

        double dR = closestPair(m, right, points, yR);

        double d = dL;

        if(double_cmp(dR, d) < 0) {

            d = dR;

        }



        for(int i = 0; i < (int) pointsByY.size(); ++i) {

            for(int j = i + 1; j < min(i + 6, (int) pointsByY.size()); ++j) {

                double tmp = getDistance(pointsByY[i], pointsByY[j]);

                if(double_cmp(tmp, d) < 0) {

                    d = tmp;

                }

            }

        }



        return d;

    }

}



int main() {

    ifstream f("cmap.in");

    ofstream g("cmap.out");



    f >> n;

    for(int i = 0; i < n; ++i) {

        Point tmp;



        f >> tmp.x >> tmp.y;

        points.push_back(tmp);

    }



    vector <Point> pointsByY = points;



    sort(points.begin(), points.end(), cmp_byXY);

    sort(pointsByY.begin(), pointsByY.end(), cmp_byY);



    g << fixed << setprecision(7) << closestPair(0, n , points, pointsByY) << "\n";



    f.close();

    g.close();



    return 0;

}
