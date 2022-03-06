#include <fstream>
#include <vector>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



vector < int > M[100003], M_T[100003], M_afis[100003];

int Viz[100003], n, m, x, y, contor, Po[100003], nr;

void dfs1 ( int nod )

{

    Viz[nod] = 1;

    for ( vector < int > ::iterator it=M[nod].begin(); it != M[nod].end(); it++ )

        if ( Viz[*it] == 0 )

            dfs1(*it);

    Po[++nr] = nod;

}

void dfs2 ( int nod )

{

    M_afis[contor].push_back(nod);

    Viz[nod] = 0;

    for ( vector < int > ::iterator it = M_T[nod].begin(); it != M_T[nod].end(); it++ )

        if ( Viz[*it] )

            dfs2(*it);

}



int main()

{

    f >> n >> m;

    for ( int i = 1; i <= m; i++ )

    {

        f >> x >> y;

        M[x].push_back(y);

        M_T[y].push_back(x);

    }

    for ( int i = 1; i <= n; i++ )

        if ( Viz[i] == 0 )

            dfs1(i);

    for ( int i = n; i >= 1; i-- )

        if ( Viz[Po[i]])

        {

            contor++;

            dfs2(Po[i]);

        }

    g << contor << '\n';

    for ( int i = 1; i <= contor; i++ )

    {

        for ( vector < int > ::iterator it = M_afis[i].begin(); it != M_afis[i].end(); it ++ )

            g << *it << " ";

        g << '\n';;

    }

    return 0;

}
