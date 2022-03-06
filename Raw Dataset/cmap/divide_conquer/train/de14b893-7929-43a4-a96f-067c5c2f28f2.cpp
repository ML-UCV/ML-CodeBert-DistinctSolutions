#include <bits/stdc++.h>
using namespace std;
typedef pair <long long, long long> point;
const long long INF = 1e18;
vector <point> points;

long long distance(point p1, point p2) {

    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}
bool cmp_y(point p1, point p2) {

    return p1.second < p2.second;

}


long long divide(int left, int right) {

    if (right-left < 3) {
        long long min_dist = INF;
        for (int i = left; i < right; i++) {
            for (int j = i + 1; j <= right; j++) {
                min_dist = min(min_dist, distance(points[i], points[j]) );
            }
        }
        return min_dist;
    }
    int mid = (left + right) / 2;
    long long min_dist_left = divide(left, mid);
    long long min_dist_right = divide(mid + 1, right);
    long long min_dist = min(min_dist_left, min_dist_right);
    vector <point> new_points;

    for (int i = left; i <= right; i++) {

        if(abs(points[mid].first-points[i].first)<min_dist){
            new_points.push_back(points[i]);
        }

    }
     sort(new_points.begin(), new_points.end(), cmp_y);
    for (int i = 0; i < new_points.size(); i++) {

        for (int j = i + 1; j < i + 8 && j < new_points.size(); j++) {

            min_dist = min(min_dist, distance(new_points[i], new_points[j]));
        }
    }
    return min_dist;
}



int main()

{
    ifstream f("cmap.in");
    ofstream g("cmap.out");
    int n;
    f >> n;
    for (int i = 0; i < n; i++) {
        point read;
        f >> read.first >> read.second;
        points.push_back(read);

    }
    sort (points.begin(), points.end());

    g << fixed << setprecision(7) << sqrt((long double) divide(0, n - 1));



    return 0;

}
