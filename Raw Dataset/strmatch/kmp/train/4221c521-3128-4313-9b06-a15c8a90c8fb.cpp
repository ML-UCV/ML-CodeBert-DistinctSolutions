#include <fstream>
#include <cstring>


using namespace std;



ifstream in ("strmatch.in");

ofstream out ("strmatch.out");



char word[2000137];

int n;





char sentence[2000137];

int m;



int pi[2000137];

int k;



int v[1137];

int sorin;



int main()

{

    in >> word + 1 >> sentence + 1;

    n = strlen ( word + 1 );

    m = strlen ( sentence + 1);

    k = 0;

    for ( register int i = 2 ; i <= n ; ++i )

    {

        while ( k > 0 && word[k+1] != word[i] )

            k = pi[k];

        if ( word[k+1] == word[i] )

            ++k;

        pi[i] = k;

    }



    k = 0;

    for ( register int i = 1 ; i <= m ; ++i )

    {

        while ( k > 0 && word[k+1] != sentence[i] )

            k = pi[k];

        if ( word[k+1] == sentence[i] )

            ++k;

        if ( k == n )

        {

            ++sorin;

            if ( sorin <= 1000 )

                v[sorin] = i - n;

            k = pi[k];

        }

    }

    out << sorin << '\n';

    sorin = min ( 1000, sorin );

    for ( register int i = 1 ; i <= sorin ; ++i )

        out << v[i] << " ";

    return 0;

}
