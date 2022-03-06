#include <bits/stdc++.h>






using namespace std;

typedef long long llong;



struct Punct

{

    int x, y;

} px[100005], tmp[100005];



bool cmpx(const Punct& a, const Punct& b)

{

    return a.x < b.x;

}



bool cmpy(const Punct& a, const Punct& b)

{

    return a.y < b.y;

}



llong dist2(const Punct& a, const Punct& b)

{

    llong dx = a.x - b.x;

    llong dy = a.y - b.y;

    return dx * dx + dy * dy;

}



llong calc(int p, int q)

{

    llong res = 0x7fffffffffffffffLL;

    for(int i = p; i < q; i++)

    {

        for(int j = i + 1; j <= q; j++)

        {

            llong aux = dist2(px[i], px[j]);

            if(aux < res)

                res = aux;

        }

    }

    return res;

}



inline llong sqr(int x)

{

    return (llong)x * x;

}



llong solve(int p, int q)

{

    if(q - p < 3)

        return calc(p, q);

    int m = (p + q) / 2;

    llong d1 = solve(p, m);

    llong d2 = solve(m, q);

    llong dd = min(d1, d2);



    int k = 0;

    for(int i = p; i <= q; i++)

    {

        if(sqr(px[i].x - px[m].x) < dd)

            tmp[k++] = px[i];

    }

    sort(tmp, tmp + k, cmpy);

    for(int i = 0; i < k; i++)

    {

        for(int j = i + 1; sqr(tmp[j].y - tmp[i].y) < dd && j < k; j++)

        {

            llong dist = dist2(tmp[i], tmp[j]);

            if(dd > dist)

                dd = dist;

        }

    }

    return dd;

}



int main()

{

    int n, i;

    ifstream fin("cmap.in");

    ofstream fout("cmap.out");

    fin >> n;

    for(i = 0; i < n; i++)

    {

        fin >> px[i].x >> px[i].y;

    }

    sort(px, px + n, cmpx);

    llong res = solve(0, n - 1);

    fout << fixed << setprecision(6) << sqrtl(res);

    return 0;

}
