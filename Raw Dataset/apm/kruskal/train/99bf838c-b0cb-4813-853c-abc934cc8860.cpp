#include <iostream>
#include <fstream>
#include <algorithm>






using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



struct muchie

{

    int x, y, c;



}v[400005];



struct elem

{

    int x, y;



}a[400005];



bool cmp(muchie i, muchie j)

{

    return i.c < j.c;

}



int tata[200005], rang[200005], n, m, i, x, y, k, s;



int tata_multime( int nod )

{

    if( tata[nod] != nod )

        tata[nod] = tata_multime( tata[nod] );

    return tata[nod];

}



void Union( int px, int py )

{

    px = tata_multime( px );

    py = tata_multime( py );

    if( px != py )

    {

        if( rang[px] < rang[py] )

        {

            rang[py] += rang[px];

            tata[px] = py;

        }

        else

        {

            rang[px] += rang[py];

            tata[py] = px;

        }

    }

}

int main()

{

    f >> n >> m;

    for( i = 1; i <= n; ++ i )

    {

        tata[i] = i;

        rang[i] = 1;

    }

    for( i = 1 ; i <= m ; ++ i )

        f >> v[i].x >> v[i].y >> v[i].c;

    sort(v + 1, v + m + 1, cmp);

    for( i = 1; i <= m; ++ i )

    {

        x = tata_multime( v[i].x );

        y = tata_multime( v[i].y );

        if( x != y )

        {

            Union( x, y );

            s = s + v[i].c;

            a[++ k].x = v[i].x;

            a[k].y = v[i].y;

        }

    }

    g << s << "\n" << k << "\n";

    for( i = 1; i <= k; ++ i )

        g << a[i].x << " " << a[i].y << "\n";

    return 0;

}
