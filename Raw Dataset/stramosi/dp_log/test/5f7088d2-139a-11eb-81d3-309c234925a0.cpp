#include <fstream>


using namespace std;



ifstream in ("stramosi.in");

ofstream out ("stramosi.out");



int n, m;



int stramosi[20][250007];



int q, p;



int main()

{

    in >> n >> m;

    for ( register int i = 1 ; i <= n ; ++i )

        in >> stramosi[0][i];

    for ( register int i = 1 ; i <= 19 ; ++i )

        for ( register int j = 1; j <= n ; ++j )

            stramosi[i][j] = stramosi[i-1][stramosi[i-1][j]];

    for ( register int querry = 1 ; querry <= m ; ++querry )

    {

        in >> q >> p;

        for ( register int i = 0 ; (1<<i) <= p ; ++i )

            if ( (1<<i)&p )

                q = stramosi[i][q];

        out << q << '\n';

    }

    return 0;

}
