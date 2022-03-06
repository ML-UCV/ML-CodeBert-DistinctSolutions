#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
using namespace std;



const char iname[] = "cmap.in";

const char oname[] = "cmap.out";





const int N = 100005;

const long long INF = 4e18;



pair <long long, long long> X[N], V[N];



long long dist(const pair <long long, long long>& a, const pair <long long, long long>& b) {

    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);

}



bool compByX(const pair <long long, long long> &a, const pair <long long, long long> &b){

    if(a.first == b.first){

        return a.second < b.second;

    }

    return a.first < b.first;

}



bool compByY(pair <long long, long long> a, pair <long long, long long> b){

    if(a.second == b.second){

        return a.first < b.first;

    }

    return a.second < b.second;

}



long long solve(int lf, int rg) {

    if (lf == rg)

        return INF;

    else if (rg - lf == 1) {

        if (X[lf].second > X[lf + 1].second)

            swap(X[lf], X[lf + 1]);

        return dist(X[lf], X[lf + 1]);

    }

    int md = (lf + rg) / 2;

    long long best = min(solve(lf, md), solve(md + 1, rg));



    merge(X + lf, X + md + 1, X + md + 1, X + rg + 1, V + 1, compByY);

    copy(V + 1, V + (rg - lf + 1) + 1, X + lf);



    int v_size = 0;

    for (int i = lf; i <= rg; ++ i) if (abs(X[i].first - X[md].first) <= best)

        V[++v_size] = X[i];

    for (int i = 1; i <= v_size;++i) {

        for (int j = i + 1; j <= v_size && j - i <= 8;++j)

            best = min(best, dist(V[i], V[j]));

    }

    return best;

}



int main() {

    freopen("cmap.in", "r", stdin);

    freopen("cmap.out", "w", stdout);

    int n;

    scanf("%d", &n);

    for (int i = 1;i <= n;++i) {

        scanf("%lld %lld", &X[i].first, &X[i].second);

    }

    sort(X + 1, X + n + 1, compByX);

    printf("%.6lf", sqrt(solve(1, n)));

    return 0;

}
