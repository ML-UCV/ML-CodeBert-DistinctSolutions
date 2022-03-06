#include <bits/stdc++.h>


using namespace std;





ifstream fin("cmap.in");

ofstream fout("cmap.out");



struct point {

    double x, y;

    point(double _x = 0, double _y = 0) :x(_x), y(_y) {}

};



ostream& operator<< (ostream& out, const point &A) {

    out << A.x << " " << A.y;

    return out;

}

inline double distance(point &a, point &b) {

    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));

}



inline bool cmpX(point &A, point& B) {

    return A.x < B.x;

}



inline bool cmpY(point &A, point& B) {

    return A.y < B.y;

}



void read(vector <point> &points) {

    int i, n;

    double x, y;

    fin >> n;

    points.resize(n);

    for (i = 0; i < n; ++i) {

        fin >> x >> y;

        points[i] = point(x, y);

    }

}



point A, B;

double smallestDistance(vector <point> &points, int left, int right) {

    if (right - left+ 1 == 2) {

        if (points[left].y > points[right].y) swap(points[left], points[right]);

        A = points[left];

        B = points[right];

        return distance(points[left], points[right]);

    }



    if (right - left + 1 == 3) {

        sort(points.begin() + left, points.begin() + right, cmpY);

        double d1 = distance(points[left], points[left + 1]);

        double d2 = distance(points[left + 1], points[right]);

        double d3 = distance(points[left], points[right]);

        if (d1 < d2) {

            if (d1 < d3) {

                A = points[left];

                B = points[left + 1];

                return d1;
            }

            A = points[left + 1];

            B = points[right];

            return d2;

        }



        A = points[left];

        B = points[right];

        return d3;

    }



    int middle = (left + right) / 2;

    double median = points[middle].x;

    double delta = min(smallestDistance(points, left, middle), smallestDistance(points, middle + 1, right));

    int nr = 0, i = left, j = middle + 1, k = 0;

    point aux[right - left + 1], rectangle[right - left + 1];

    while (i <= middle && j <= right) {

        if (points[i].y < points[j].y)

            aux[k++] = points[i++];

        else

            aux[k++] = points[j++];

    }



    while (i <= middle)

        aux[k++] = points[i++];

    while (j <= right)

        aux[k++] = points[j++];





    for (i = left; i <= right; ++i) {

        points[i] = aux[i - left];

        if (points[i].x - median <= delta && points[i].x - median >= -delta) {

            rectangle[nr++] = points[i];

        }

    }



    for (i = 0; i < nr; ++i) {

        int neighboursNumber = min(nr, i + 8);



        for (j = i + 1; j < neighboursNumber; ++j) {

            if (distance(rectangle[i], rectangle[j]) < delta) {

                delta = distance(rectangle[i], rectangle[j]);

                A = rectangle[i];

                B = rectangle[j];

            }

        }

    }

    return delta;

}

int main() {

    vector <point> points;

    read(points);

    sort(points.begin(), points.end(), cmpX);

    double dist = smallestDistance(points, 0, points.size() - 1);

    fout << setprecision(6) << fixed << dist << "\n";

}
