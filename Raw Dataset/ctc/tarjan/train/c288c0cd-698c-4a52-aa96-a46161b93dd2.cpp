#include <fstream>
#include <vector>
#include <stack>


using namespace std;



ifstream in ("ctc.in");

ofstream out ("ctc.out");



const int LIM = 1e5 + 7;



void tarjan ( int nod );



vector < int > g[LIM];



vector < int > ctc[LIM];



stack < int > s;



int n, m;



int x, y;



int viz[LIM];



int iss[LIM];



int niv[LIM];



int l[LIM];



int ct;



int sorin;



int main()

{

    in >> n >> m;

    for ( int i = 1 ; i <= m ; ++i )

    {

        in >> x >> y;

        g[x].push_back (y);

    }

    for ( int i = 1 ; i <= n ; ++i )

        if ( !viz[i] )

            tarjan (i);

    out << sorin << '\n';

    for ( int i = 1 ; i <= sorin ; ++i )

    {

        for ( auto y : ctc[i] )

            out << y << " ";

        out << '\n';

    }

    return 0;

}



void tarjan ( int nod )

{

    iss[nod] = true;

    viz[nod] = true;

    s.push(nod);

    niv[nod] = l[nod] = ++ct;

    for ( auto y : g[nod] )

    {

        if ( !viz[y] )

        {

            tarjan (y);

            l[nod] = min ( l[nod], l[y] );

        }

        else

        {

            if ( iss[y] )

                l[nod] = min ( l[nod], niv[y] );

        }

    }

    if ( niv[nod] == l[nod] )

    {

        ++sorin;

        while ( !s.empty () )

        {

            ctc[sorin].push_back ( s.top () );

            iss[s.top ()] = false;

            if ( s.top () == nod )

            {

                s.pop ();

                break;

            }

            s.pop ();

        }

    }

}
