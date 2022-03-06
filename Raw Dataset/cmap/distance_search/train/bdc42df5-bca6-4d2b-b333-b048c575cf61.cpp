#include <bits/stdc++.h>






using namespace std;



FILE *fin = freopen("cmap.in", "r", stdin);

FILE *fout = freopen("cmap.out", "w", stdout);



int n;

struct Point

{

    int x, y;

    bool operator < (const Point &ot) const

    {

        if (x == ot.x)

            return y < ot.y;

        return x < ot.x;

    }

} v[100002];

set < Point > s;



long long sqr(int x)

{

    return 1LL * x * x;

}

double dist(Point a, Point b)

{

    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));

}

double h;



int main()

{

    scanf("%d", &n);

    for (int i = 0; i < n; ++ i)

        scanf("%d%d", &v[i].x, &v[i].y);

    auto it = 0;

    sort(v, v + n);

    h = dist(v[0], v[1]);

    for (int i = 0; i < n; ++ i)

    {

        while (it < i && h <= (double)v[i].x - v[it].x)

        {

            s.erase(s.find(Point{v[it].y, v[it].x}));

            ++ it;

        }

        int H = (int)(h);

        auto it1 = s.lower_bound(Point{v[i].y - H,-0x3fffffff}),

             it2 = s.upper_bound(Point{v[i].y + H, 0x3fffffff});

        if (it2 != s.begin() && it1 != s.end())

        {

            for (auto j = it1; j != it2; ++ j)

                h = min(h, dist(v[i], Point{it1->y, it1->x}));

        }

        s.insert(Point{v[i].y, v[i].x});

    }



    printf("%.7lf", h);

    return 0;

}
