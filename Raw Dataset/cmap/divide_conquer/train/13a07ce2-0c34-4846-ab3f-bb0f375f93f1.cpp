#include <bits/stdc++.h>

using namespace std;

ifstream f("cmap.in");
ofstream g("cmap.out");

long long inf = (1LL << 60) ;
const int nmax = 1e5 + 5;

struct coor
{
    long long x;
    long long y;
};

long double dis(coor a, coor b)
{
    long double x = a.x - b.x;
    long double y = a.y - b.y;
    return sqrt(x * x + y * y);
}

coor point[nmax];
coor sorted[nmax];

long double divide(int i, int j)
{
    if (j - i + 1 <= 3)
    {
        long double ans = inf;
        for (int a = i; a < j; ++ a)
            for (int b = a + 1; b <= j; ++ b)
                ans = min(ans, dis(point[a], point[b]));
        return ans;
    }
    int mij = (i + j) / 2;
    long double ans = min(divide(i, mij), divide(mij + 1, j));
    int line = point[mij].x;
    int cnt = 0;
    for (int k = i; k <= j; ++ k)
        if (abs(line - point[k].x) <= ans)
            sorted[++ cnt] = point[k];
    sort(sorted + 1, sorted + 1 + cnt, [] (coor a, coor b) -> bool
    {
        return a.y < b.y;
    });
    for (int a = 1; a < cnt; ++ a)
        for (int b = a + 1; b <= cnt && b - a < 8; ++ b)
            ans = min(ans, dis(sorted[a], sorted[b]));
    return ans;
}

int main()
{
    int n;
    f >> n;
    for (int i = 1; i <= n; ++ i)
    {
        long long x, y;
        f >> x >> y;
        point[i - 1] = {x, y};
    }
    sort(point, point + n, [] (coor a, coor b) -> bool
    {
        return a.x < b.x;
    });
    g << setprecision(6) << fixed << divide(0, n - 1);
}
