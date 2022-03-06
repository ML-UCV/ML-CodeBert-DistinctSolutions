#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>






using namespace std;



typedef pair<long long, long long> point;

vector<point> points;



void read() {



    ifstream in("cmap.in");



    int n;

    long long x, y;



    for (in >> n; n; --n) {



        in >> x >> y;



        points.push_back(make_pair(x, y));

    }



    in.close();

}



bool compareY(const point &p1, const point &p2) {



    return (p1.second <= p2.second);

}



long long dist(const point& p1, const point &p2) {



    return (p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second);

}



long long bruteMinDist(int left, int right) {



    long long minValue = 0;



    for (int i = left; i < right; i++)

        for (int j = i + 1; j <= right; j++) {



            if (minValue == 0)

                minValue = dist(points[i], points[j]);

            else

                minValue = min(minValue, dist(points[i], points[j]));



        }



    return minValue;

}



long long stripMinDist(const vector<point>& strip, long long delta) {



    long long minDist = delta;



    for (unsigned int i = 0; i < strip.size(); i++)

        for (unsigned int j = i + 1; j < strip.size() && (strip[i].second - strip[j].second) * (strip[i].second - strip[j].second) <= delta; j++)

            minDist = min(minDist, dist(strip[i], strip[j]));



    return minDist;

}



long long mergeSort(int left, int right) {



    if (right - left <= 2) {



        sort(points.begin() + left, points.begin() + right + 1, compareY);

        return bruteMinDist(left, right);



    } else {



        int mid = left + (right - left) / 2;

        long long midX = points[mid].first;



        long long dist1 = mergeSort(left, mid);

        long long dist2 = mergeSort(mid + 1, right);

        long long delta = min(dist1, dist2);







        vector<point> result;

        result.resize(right - left + 1);



        merge(points.begin() + left, points.begin() + mid + 1, points.begin() + mid + 1, points.begin() + right + 1, result.begin(), compareY);

        copy(result.begin(), result.end(), points.begin() + left);







        vector<point> strip;



        for (int i = left; i <= right; i++)

            if ((midX - points[i].first) * (midX - points[i].first) <= delta)

                strip.push_back(points[i]);



        long long dist3 = stripMinDist(strip, delta);



        return min(delta, dist3);

    }

}



int main() {



    read();

    sort(points.begin(), points.end());



    long long minDist = mergeSort(0, points.size() - 1);



    ofstream out("cmap.out");

    out << fixed << setprecision(6) << sqrt(minDist) << "\n";

    out.close();



    return 0;

}
