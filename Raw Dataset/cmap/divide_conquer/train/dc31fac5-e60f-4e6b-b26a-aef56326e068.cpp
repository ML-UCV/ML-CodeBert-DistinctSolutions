#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <limits.h>


using namespace std;
ifstream f("cmap.in");

ofstream g("cmap.out");



int n;

pair<int, int> points[100000], pointsY[100000], aux[100000];



long long d(pair<int, int> a, pair<int, int> b){

    return 1LL * (a.first - b.first) * (a.first - b.first) + 1LL * (a.second - b.second) * (a.second - b.second);

}



long long minDist(int l, int r){

    if(r == l)

        return 1e18;

    else if(r - l == 1){

        if(pointsY[r] < pointsY[l])

            swap(pointsY[l], pointsY[r]);

        return d(pointsY[l], pointsY[r]);

    }

    int mid = (l + r) >> 1;

    long long minD = min( minDist(l, mid), minDist(mid + 1, r));

    merge(pointsY + l, pointsY + mid + 1, pointsY + mid + 1, pointsY + r + 1, aux);

    copy(aux, aux + (r - l + 1), pointsY + l);



    int k = 0;

    for(int i = l; i <= r; i++)

        if(abs(points[mid].first - pointsY[i].second) <= minD && i != mid)

            aux[k++] = pointsY[i];



    for(int i = 0; i < k; i++)

        for(int j = i + 1; j < k && j <= i + 8; j++)

            minD = min(minD, d(aux[i], aux[j]));



    return minD;

}



int main()

{

    f >> n;

    for(int i = 0; i < n; i++)

        f >> points[i].first >> points[i].second;



    sort(points, points + n);

    for(int i = 0; i < n; i++)

        pointsY[i] = make_pair(points[i].second, points[i].first);



    g << fixed << setprecision(6) << sqrt(minDist(0, n - 1));

    return 0;

}
