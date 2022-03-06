#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");

vector<pair<int,int> > v;

int n;

long long inf = 1 << 60;

long long dst(pair<int,int> p1, pair<int,int> p2) {

    return (long long)(p1.first - p2.first) * (p1.first - p2.first) + (long long)(p1.second - p2.second) * (p1.second - p2.second);

}



bool compx(pair<int, int> p1, pair<int, int> p2) {

    return p1.first < p2.first;

}



bool compy(pair<int, int> p1, pair<int, int> p2) {

    return p1.second < p2.second;

}



long long dist(vector<pair<int,int> > &v,int st,int dr) {

    if(dr - st == 1)

        return dst(v[st], v[dr]);

    if(dr - st == 2) {

           long long d1,d2,d3;

           d1 = dst(v[st], v[dr]);

           d2 = dst(v[st+1], v[dr]);

           d3 = dst(v[st], v[st+1]);

           return min(d1, min(d2, d3));

       }

    int mid=(st + dr) / 2;

    long long d, d1, d2, x;

    d1 = dist(v, mid + 1, dr);

    d2 = dist(v, st, mid);

    d = min(d1, d2);

    x = (int) ceil(sqrt(d));

    vector <pair <int,int> > s;

    for(int i = st;i <= dr; i ++)

    if(abs(v[i].first - v[mid].first) <= x)

       s.push_back(v[i]);

    sort(s.begin(), s.end(), compy);

    for(int i = 0;i < s.size(); i ++)

    for(int j = i + 1; j <= i + 7 && j <s.size(); j ++)

        d = min(d, dst(s[i], s[j]));

    return d;

}



int main()

{

    f >> n;

    for(int i = 1; i <= n; i ++) {

        int x, y;

        f >> x >> y;

        v.push_back(make_pair(x, y));

    }

    sort(v.begin(), v.end(), compx);

    g << fixed << setprecision(6) << sqrt(dist(v, 0, n - 1)) << "\n";

    return 0;

}
