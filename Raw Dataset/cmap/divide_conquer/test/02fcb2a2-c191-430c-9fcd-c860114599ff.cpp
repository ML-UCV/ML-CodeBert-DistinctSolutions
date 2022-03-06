#include <bits/stdc++.h>






using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



class point {

    public:

        long long x, y;

};



long long dist(const point &p1, const point &p2) {

    return ((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y));

}



long long smallest_distance(const vector<point> &points, const vector<point> &points_by_y) {

    long long N = points.size();

    if(N < 2)

        return 9e18L;

    vector<point> left = vector<point>(points.begin(), points.begin() + N / 2),

                  right = vector<point>(points.begin() + N / 2, points.end());

    vector<point> left_by_y, right_by_y;

    for(const point &p : points_by_y)

        if(make_pair(p.x, p.y) <= make_pair(left.back().x, left.back().y))

            left_by_y.emplace_back(p);

        else

            right_by_y.emplace_back(p);

    long long d1 = smallest_distance(left, left_by_y),

        d2 = smallest_distance(right, right_by_y),

        d = min(d1, d2);

    long long middle_x = left.back().x;

    vector<point> stripe;

    for(const point &p : points_by_y)

        if(((p.x - middle_x) * (p.x - middle_x)) < d)

            stripe.emplace_back(p);

    long long M = stripe.size();

    for(long long i = 0; i < M; ++i) {



        for(long long j = i + 1; j < M && ((stripe[j].y - stripe[i].y) * (stripe[j].y - stripe[i].y)) < d; ++j)

            d = min(d, dist(stripe[i], stripe[j]));

    }

    return d;

}



void test_case() {

    long long N;

    fin >> N;

    vector<point> points(N);

    for(point &p : points)

        fin >> p.x >> p.y;

    sort(points.begin(), points.end(), [&](const point &A, const point &B) -> bool {

        return make_pair(A.x, A.y) < make_pair(B.x, B.y);

    });

    vector<point> y_sorted = points;

    sort(y_sorted.begin(), y_sorted.end(), [&](const point &A, const point &B) -> bool {

        return A.y < B.y;

    });

    fout << fixed << setprecision(8) << sqrtl(smallest_distance(points, y_sorted)) << '\n';

}



int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);

    long long T = 1;

    while(T--)

        test_case();

}
