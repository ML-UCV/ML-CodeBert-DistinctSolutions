#include <bits/stdc++.h>




using namespace std;

typedef long long llong;



struct Punct

{

    int x, y;

} px[100005], tmp[100005];



bool cmpx(const Punct& a, const Punct& b)

{

    if(a.x == b.x) return a.y < b.y;

    return a.x < b.x;

}



bool cmpy(const Punct& a, const Punct& b)

{

    if(a.y == b.y) return a.x < b.x;

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

    sort(px + p, px + q + 1, cmpy);

    return res;

}



inline llong sqr(int x)

{

    return (llong)x * x;

}



void inter(int p, int q, int m)

{

    int i = p, j = m + 1, k;

    for(k = p; i <= m && j <= q; k++)

    {

        if(cmpy(px[i], px[j]))

            tmp[k] = px[i++];

        else tmp[k] = px[j++];

    }

    for(; i <= m; i++)

        tmp[k++] = px[i];

    for(; j <= q; j++)

        tmp[k++] = px[j];

}



llong solve(int p, int q)

{

    if(q - p < 3)

        return calc(p, q);

    int m = (p + q) / 2;

    int mx = px[m].x;

    llong d1 = solve(p, m);

    llong d2 = solve(m + 1, q);

    llong dd = min(d1, d2);





    inter(p, q, m);



    int k = 0;

    for(int i = p; i <= q; i++)

    {

        px[i] = tmp[i];

        if(sqr(px[i].x - mx) < dd)

            tmp[k++] = px[i];

    }



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
