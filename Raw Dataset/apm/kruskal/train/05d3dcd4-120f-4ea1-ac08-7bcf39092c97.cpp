#include <fstream>
#include <algorithm>


using namespace std;



ifstream in ("apm.in");

ofstream out ("apm.out");



struct ura

{

    int x, y;

    int cost;

} muchii[400137];



bool cmp ( ura a, ura b );



int findee ( int nod );



void gluee ( int nod1, int nod2 );



int n, m;



int h[400137];



int r[400137];



int t[400137];



int nr;



int sorin;



int main()

{

    in >> n >> m;

    for ( register int i = 1 ; i <= m ; ++i )

        in >> muchii[i].x >> muchii[i].y >> muchii[i].cost;

    sort ( muchii + 1, muchii + m + 1, cmp );

    for ( register int i = 1 ; i <= n ; ++i )

        h[i] = 1;

    int i = 1;

    while ( nr < n - 1 )

    {

        int nod1 = muchii[i].x;

        int nod2 = muchii[i].y;

        int t1 = findee (nod1);

        int t2 = findee (nod2);

        if ( t1 != t2 )

        {

            ++nr;

            r[++r[0]] = nod2;

            r[++r[0]] = nod1;

            sorin += muchii[i].cost;

            gluee ( t1, t2 );

        }

        ++i;

    }

    out << sorin << '\n';

    out << nr << '\n';

    i = 1;

    while ( i <= r[0] )

    {

        out << r[i] << " " << r[i + 1] << '\n';

        i += 2;

    }

    return 0;

}



bool cmp ( ura a, ura b )

{

    return a.cost < b.cost;

}



int findee ( int nod )

{

    while ( t[nod] != 0 )

        nod = t[nod];

    return nod;

}



void gluee ( int nod1, int nod2 )

{

    if ( h[nod1] > h[nod2] )

        t[nod2] = nod1;

    else

    {

        t[nod1] = nod2;

        if ( h[nod1] == h[nod2] )

            ++h[nod2];

    }

}
