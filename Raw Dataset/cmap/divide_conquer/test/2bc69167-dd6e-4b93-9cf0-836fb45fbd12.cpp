#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>


using namespace std;



ifstream in("cmap.in");

ofstream out("cmap.out");



struct Point {

    int x, y;

};



int pointsCompareFunctionYAxis(Point p1, Point p2) {

    return p1.y < p2.y;

}



int pointsCompareFunctionXAxis(Point p1, Point p2) {

    return p1.x < p2.x;

}



int nrPoints;

vector<Point> points;



void read() {

    in >> nrPoints;

    Point point;

    for (int i = 0; i < nrPoints; ++i) {

        in >> point.x >> point.y;

        points.push_back(point);

    }

}



long long int euclidianDistance(Point p1, Point p2) {

    return 1LL * (p1.x - p2.x) * (p1.x - p2.x) + 1LL * (p1.y - p2.y) * (p1.y - p2.y);

}



void intersect(int left, int right, int pivot) {

    int i = left, j = pivot + 1;

    vector<Point> temp;

    while (i <= pivot && j <= right) {

        if (points[i].y < points[j].y)

            temp.push_back(points[i++]);

        else

            temp.push_back(points[j++]);

    }

    while (i <= pivot)

        temp.push_back(points[i++]);

    while (j <= right)

        temp.push_back(points[j++]);

    for (int k = left; k <= right; ++k)

        points[k] = temp[k - left];

}



long long int getMinDistance(int left, int right) {

    if (right - left == 1) {

        if (points[left].y > points[right].y)

            swap(points[left], points[right]);

        return euclidianDistance(points[left], points[right]);

    }

    if (right - left == 2) {

        sort(points.begin() + left, points.begin() + right + 1, pointsCompareFunctionYAxis);

        return min(euclidianDistance(points[left], points[left + 1]),

                    min(euclidianDistance(points[left], points[left + 2]),

                        euclidianDistance(points[left + 1], points[left + 2])));

    }

    int pivot = (right - left) / 2 + left;

    int pivotX = points[pivot].x;

    long long int minDistance = min(getMinDistance(left, pivot), getMinDistance(pivot + 1, right));

    intersect(left, right, pivot);

    int bandWidth = ceil(sqrt(minDistance));

    vector<Point> band;

    for (int i = left; i <= right; ++i)

        if (abs(points[i].x - pivotX) <= bandWidth)

            band.push_back(points[i]);

    int bandLength = band.size();

    for (int i = 0; i < bandLength; ++i)

        for (int j = i + 1; j <= i + 7 && j < bandLength; ++j)

            minDistance = min(minDistance, euclidianDistance(band[i], band[j]));

    return minDistance;

}



int main()

{

    read();

    sort(points.begin(), points.end(), pointsCompareFunctionXAxis);

    out << fixed << setprecision(8) << sqrt(getMinDistance(0, nrPoints - 1)) << '\n';

    return 0;

}
