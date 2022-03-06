#include <fstream>
#include <iostream>
#include <algorithm>


using namespace std;

ifstream in ("inv.in");

ofstream out ("inv.out");



const int MAXN = 100000;

pair <int, int> vp[1 + MAXN];

bool sortVal (pair <int, int> pair1, pair <int, int> pair2)

{

    return pair1.second < pair2.second;

}

bool sortInd (pair <int, int> pair1, pair <int, int> pair2)

{

    return pair1.first < pair2.first;

}



int arb[4 * MAXN];

int l, r;

int query (int p, int st, int dr)

{

    if (l <= st && dr <= r)

        return arb[p];

    else

    {

        int ans = 0;

        int m = (st + dr) / 2;

        if(l <= m)

            ans += query (2 * p, st, m);

        if(r >= m + 1)

            ans += query (2 * p + 1, m + 1, dr);

        return ans;

    }

}



int poz;

void update (int p, int st, int dr)

{

    if (st == dr)

        arb[p]++;

    else

    {

        int m = (st + dr) / 2;

        if(poz <= m)

            update (2 * p, st, m);

        else

            update (2 * p + 1, m + 1, dr);

        arb[p] = arb[2 * p] + arb[2 * p + 1];

    }

}



int main()

{

    int n;

    in >> n;

    for (int i = 1; i <= n; i++)

    {

        in >> vp[i].second;

        vp[i].first = i;

    }



    sort (vp + 1, vp + n + 1, sortVal);



    int ant = vp[1].second;

    vp[1].second = 1;

    for (int i = 2; i <= n; i++)

    {

        if (vp[i].second == ant)

        {

            vp[i].second = vp[i-1].second;

        }

        else

        {

            ant = vp[i].second;

            vp[i].second = vp[i-1].second + 1;

        }

    }



    sort (vp + 1, vp + n + 1, sortInd);



    int rez = 0;

    for (int i = 1; i <= n; i++)

    {

        l = vp[i].second + 1;

        r = n;

        if(l <= r)

            rez += query(1, 1, n);

        rez %= 9917;



        poz = vp[i].second;

        update(1, 1, n);

    }

    out<<rez;

    return 0;

}
