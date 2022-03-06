#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmap.in");
ofstream fout("cmap.out");


typedef pair<double,double> point;
const int MAXN = 100010;
const double INF = 1e16;
const int PRECISION = 6;
vector<point> V(MAXN);
int N;

double dist( point p1, point p2) {
    return sqrt( (p1.first - p2.first)*(p1.first - p2.first) +
                (p1.second - p2.second)*(p1.second - p2.second)
            );
}

double bruteForce(int from, int to) {
    double rs = INF;
    for (int i = from; i <= to; i++)
        for (int j = i + 1; j <= to; j++ )
            rs = min(rs, dist(V[i], V[j]));

    return rs;
}

double closestOverlapping(vector<point> &strip, double minDist) {
    sort(strip.begin(), strip.end(), [](point a, point b) {

        swap(a.first, a.second); swap(b.first, b.second);
        return a < b;
    });
    for (int i = 0; i < strip.size(); i++)
        for (int j = i + 1; j < strip.size() && (strip[j].second - strip[i].second < minDist); j++)
            minDist = min(minDist, dist(strip[i], strip[j]));

    return minDist;
}

double minDist(int left ,int right) {

    if (right - left + 1 <= 3)
        return bruteForce(left, right);


    int mid = (left + right) / 2;
    point midPoint = V[mid];
    double leftDist = minDist(left, mid);
    double rightDist = minDist(mid + 1, right);
    double localMinDist = min(leftDist, rightDist);
    vector<point> strip;

    for (int i = left; i <= right; i++)
        if (abs(V[i].first - midPoint.first) < localMinDist)
            strip.push_back(V[i]);

    return min(localMinDist, closestOverlapping(strip, localMinDist));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    fin >> N;
    for (int i = 1; i <= N; i++) {
        point tmp;
        fin >> tmp.first >> tmp.second;
        V[i - 1] = tmp;
    }
    V.resize(N);
    sort(V.begin(), V.end());

    fout << fixed << setprecision(PRECISION) <<minDist(0, N - 1);

    return 0;
}
