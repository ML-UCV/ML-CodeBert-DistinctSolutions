#include <bits/stdc++.h>
using namespace std;



typedef long long lint;



const lint sqrInf = 1LL * 4000000000000000000LL;



int n;



struct coord

{

    int x, y;

};



coord v[100000 + 1];

coord Y[100000 + 1];

coord x[100000 + 1];



void readFile()

{

    ifstream f("cmap.in");



    f >> n;



    for(int i = 1; i <= n; i ++)

        f >> v[i].x >> v[i].y;



    f.close();

}



struct cmpY

{

    bool operator() (coord a, coord b)

    {

        if(a.y != b.y)

            return a.y < b.y;



        return a.x < b.x;

    }

};



lint dist(coord a, coord b)

{

    lint dx = a.x - b.x;

    lint dy = a.y - b.y;



    return dx * dx + dy * dy;

}



bool cmp2(coord a, coord b)

{

    if(a.y != b.y)

        return a.y < b.y;



    return a.x < b.x;

}



void mergeSort(int st1, int dr1, int st2, int dr2)

{

    int cr = 0;

    int i = st1;

    int j = st2;

    while(i <= dr1 && j <= dr2)

    {

        int val = cmp2(Y[i], Y[j]);

        if(val == 1)

            x[++ cr] = Y[i ++];



        else

            x[++ cr] = Y[j ++];

    }



    while(i <= dr1)

        x[++ cr] = Y[i ++];



    while(j <= dr2)

        x[++ cr] = Y[j ++];



    for(i = st1; i <= dr2; i ++)

        Y[i] = x[i - st1 + 1];

}



inline int poz(int a)

{

    return (a > 0 ? a : (-a));

}



lint dmin(int st, int dr)

{

    if(st == dr)

        return sqrInf;



    if(dr - st + 1 <= 3)

    {

        sort(Y + st, Y + dr + 1, cmpY());



        lint rez = sqrInf;

        int i, j;

        for(i = st; i <= dr; i ++)

        {

            for(j = i + 1; j <= dr; j ++)

                rez = min(rez, dist(Y[i], Y[j]));

        }



        return rez;

    }



    int mid = ((st + dr) >> 1);

    lint d = min(dmin(st, mid), dmin(mid + 1, dr));



    mergeSort(st, mid, mid + 1, dr);

    int i;

    int k = 0;

    for(i = st; i <= dr; i ++)

    {

        if(poz(Y[i].x - v[mid].x) <= d)

            x[++ k] = Y[i];

    }



    int j;

    for(i = 1; i <= k; i ++)

    {

        for(j = i + 1; j <= i + 5 && j <= k; j ++)

            d = min(d, dist(x[i], x[j]));

    }



    return d;

}



struct cmp

{

    bool operator() (coord a, coord b)

    {

        if(a.x != b.x)

            return a.x < b.x;



        return a.y < b.y;

    }

};



lint rez;



void solve()

{

    sort(v + 1, v + n + 1, cmp());



    int i;

    for(i = 1; i <= n; i ++)

        Y[i] = v[i];



    rez = dmin(1, n);

}



void printFile()

{

    ofstream g("cmap.out");



    g << fixed << setprecision(6) << sqrt(rez) << "\n";



    g.close();

}



int main()

{

    readFile();



    solve();



    printFile();



    return 0;

}
