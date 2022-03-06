#include <fstream>
using namespace std;

const unsigned long long baza = 1010012383;

const unsigned long long m = 1010012359;

int v[ 1005 ], poz;

unsigned long long sol;

string a, b;



int main()

{

    ifstream fin( "strmatch.in" );

    fin >> a >> b;

    fin.close();

    if( a.size() > b.size() ){

        FILE *fout = fopen( "strmatch.out", "w" );

        fprintf( fout, "0\n" );

        fclose( fout );

    } else {

        unsigned long long vala = 0;

        unsigned long long valb = 0;

        unsigned long long put = 1, i;

        for( i = 0; i < a.size(); i++ ){

            vala = ( vala * baza + a[ i ] ) % m;

            put = ( put * baza ) % m;

        }

        for( i = 0; i < a.size(); i++ )

            valb = ( valb * baza + b[ i ] ) % m;

        if( vala == valb ){

            ++sol;

            v[ poz++ ] = 0;

        }

        for( i = 1; i <= b.size() - a.size(); i++ ){

            valb = ( valb * baza + b[ i + a.size() - 1 ] ) % m;

            unsigned long long ceva = ( put * b[ i - 1 ] ) % m;

            valb = ( valb - ceva + m ) % m;

            if( vala == valb ){

                ++sol;

                if( poz < 1000 )

                    v[ poz++ ] = i;

            }

        }

        FILE *fout = fopen( "strmatch.out", "w" );

        fprintf( fout, "%lld\n", sol );

        for( i = 0; i < poz; i++ )

            fprintf( fout, "%lld ", v[ i ] );

        fprintf( fout, "\n" );

        fclose( fout );

    }

    return 0;

}
