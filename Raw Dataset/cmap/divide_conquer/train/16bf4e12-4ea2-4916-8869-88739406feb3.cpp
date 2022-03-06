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

    friend struct byX;
    struct byX {
        bool operator() (Point const &p1, Point const &p2) {
            return p1.x < p2.x;
        }
    };

    friend struct byY;
    struct byY {
        bool operator() (Point const &p1, Point const &p2) {
            return p1.y > p2.y;
        }
    };
};





void read(long long &n, vector<Point> &points) {
    ifstream fin("cmap.in");
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
}


double distance(const Point &A, const Point &B) {
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}




double minDistanceBetweenNPoints(int li, int ls, vector<Point> &points) {
    double minDist = LLONG_MAX;
    for (int i = li; i < ls; i++) {
        for (int j = i + 1; j <= ls; j++) {
            double auxDist = distance(points[i], points[j]);
            if (minDist > auxDist) {
                minDist = auxDist;
            }
        }
    }

    return minDist;
}


double divide(int li, int ls, vector<Point> &P, vector<Point> &Q) {
    if (ls - li < 3) {
        return minDistanceBetweenNPoints(li, ls, P);
    }


    int mid = (li + ls)/2;



    vector<Point> Ql;
    Ql.push_back(Q[0]);
    vector<Point> Qr;
    Qr.push_back(Q[0]);
    for (int i = 1; i < Q.size(); i++) {
        if (Q[i].x <= P[mid].x) {
            Ql.push_back(Q[i]);
        } else {
            Qr.push_back(Q[i]);
        }
    }


    double dl = divide(li, mid, P, Ql);
    double dr = divide(mid + 1, ls, P, Qr);
    double dmin = min(dl, dr);





    vector<Point> strip;
    Point aux;
    aux.x = INT_MAX;
    aux.y = INT_MAX;
    strip.push_back(aux);
    for (int i = 1; i < Q.size(); i++) {
        if (abs(P[mid].x - Q[i].x) <= dmin) {
            strip.push_back(Q[i]);
        }
    }


    for (int i = 1; i < strip.size() - 1; i++) {
        for (int j = i + 1; j < i + 7 && j < strip.size(); j++) {
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
    vector<Point> P;

    read(n, P);

    vector<Point> Q = P;

    sort(P.begin() + 1, P.end(), Point::byX());

    sort(Q.begin() + 1, Q.end(), Point::byY());


    ofstream fout("cmap.out");
    fout << fixed << setprecision(6) << divide(1, n, P, Q);
    fout.close();
    return 0;
}
