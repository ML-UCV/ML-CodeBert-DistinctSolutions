#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
using namespace std;



const int MAX_N = 100005;

const long long INF = 4e18;



vector < pair <long long, long long> > Temp(MAX_N), X, Y;



long long dist(const pair <long long, long long>& a, const pair <long long, long long>& b) {

    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);

}



long long divide(int left, int right, vector < pair <long long, long long> >& X, vector < pair <long long, long long> >& Y) {

    if (left >= right - 1)

        return INF;

    else if (right - left == 2) {

        if (Y[left] > Y[left + 1])

            swap(Y[left], Y[left + 1]);

        return dist(X[left], X[left + 1]);

    }

    int mid = (left + right) / 2;

    long long best = min(divide(left, mid, X, Y), divide(mid, right, X, Y));



    merge(Y.begin() + left, Y.begin() + mid, Y.begin() + mid, Y.begin() + right, Temp.begin());

    copy(Temp.begin(), Temp.begin() + (right - left), Y.begin() + left);



    int v_size = 0;

    for (int i = left; i < right; ++ i) if (abs(Y[i].second - X[mid].first) <= best)

        Temp[v_size ++] = Y[i];

    for (int i = 0; i < v_size - 1; ++ i) {

        for (int j = i + 1; j < v_size && j - i < 8; ++ j)

            best = min(best, dist(Temp[i], Temp[j]));

    }

    return best;

}



int main(void) {

    int n;

    ifstream f("cmap.in");

    assert(f >> n);

    assert(1 <= n && n <= 100000);



    X.resize(n), Y.resize(n);

    for (int i = 0; i < (int) X.size(); i++) {

        assert(f>> X[i].first >> X[i].second);

        assert(-1000000000 <= X[i].first && X[i].first <= +1000000000);

        assert(-1000000000 <= X[i].second && X[i].second <= +1000000000);

    }

    f.close();



    sort(X.begin(), X.end());

    for (int i = 0; i < (int) X.size(); ++ i)

        Y[i] = make_pair(X[i].second, X[i].first);



    ofstream g("cmap.out");

    g << fixed << setprecision(6) << sqrt(divide(0, (int) X.size(), X, Y)) << "\n";

    g.close();

    return 0;

}
