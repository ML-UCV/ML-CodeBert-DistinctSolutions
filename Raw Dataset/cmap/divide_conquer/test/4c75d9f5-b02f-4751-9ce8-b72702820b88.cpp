#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;



pair <int, int> v[100010];

vector <int> p;



long long dist (int st, int dr)

{

    return (1LL * (v[dr].first - v[st].first) * (v[dr].first - v[st].first) + 1LL * (v[dr].second - v[st].second) * (v[dr].second - v[st].second));

}



void del ()

{

    vector <int> aux;

    aux.swap (p);

}



long long aabs (int a)

{

    return 1LL * max (a, -a);

}



long long divide (int st, int dr)

{

    if (dr - st + 1 <= 3)

    {

        if (dr - st + 1 == 2) return dist (st, dr);

        else return min (min (dist (st, st + 1), dist (st, st + 2)), dist (st + 1, st + 2));

    }



    int mij = (st + dr) >> 1;

    long long bst = min (divide (st, mij), divide (mij + 1, dr));



    del ();

    for (int i = st; i <= dr; ++i)

        if (aabs (v[mij].first - v[i].first) <= bst) p.push_back (i);



    for (int i = 0; i < p.size (); ++i)

        for (int j = i + 1; j <= i + 5 && j < p.size (); ++j)

            bst = min (bst, dist (p[i], p[j]));



    return bst;

}



int main ()

{

    freopen ("cmap.in", "r", stdin);

    freopen ("cmap.out", "w", stdout);



    int n;

    scanf ("%d", &n);



    for (int i = 1; i <= n; ++i)

        scanf ("%d %d", &v[i].first, &v[i].second);



    sort (v + 1, v + n + 1);



    printf ("%.8f\n", sqrt (1LL * divide (1, n)));



    return 0;

}
