#include <fstream>
#include <cstring>
using namespace std;



ifstream fin ("strmatch.in");

ofstream fout ("strmatch.out");



int i, lg_a, lg_b, r[2000003];

int Hash_a1, Hash_a2, Hash1, Hash2, P1 = 1, P2 = 1;

char a[2000003], b[2000003];



int main()

{

    fin.getline ( a, 2000005 );

    fin.getline ( b, 2000005 );



    lg_a = strlen ( a );

    lg_b = strlen ( b );

    if ( lg_a > lg_b )

    {

        fout << 0;

        return 0;

    }



    for ( i = 0 ; i < lg_a ; i++ )

    {

        Hash_a1 = ( Hash_a1 * 80 + ( a[i] - '0' + 1 ) ) % 100003;

        Hash_a2 = ( Hash_a2 * 80 + ( a[i] - '0' + 1 ) ) % 100019;



        Hash1 = ( Hash1 * 80 + ( b[i] - '0' + 1 ) ) % 100003;

        Hash2 = ( Hash2 * 80 + ( b[i] - '0' + 1 ) ) % 100019;



        if ( i != 0 )

        {

            P1 = ( P1 * 80 ) % 100003;

            P2 = ( P2 * 80 ) % 100019;

        }

    }



    if ( Hash_a1 == Hash1 && Hash_a2 == Hash2 ) r[++r[0]] = 0;



    for ( i = lg_a ; i < lg_b ; i++ )

    {

        Hash1 = ( ( ( Hash1 - ( ( b[i-lg_a] - '0' + 1 ) * P1 ) % 100003 + 100003 ) * 80 ) % 100003 + ( b[i] - '0' + 1 ) ) % 100003;

        Hash2 = ( ( ( Hash2 - ( ( b[i-lg_a] - '0' + 1 ) * P2 ) % 100019 + 100019 ) * 80 ) % 100019 + ( b[i] - '0' + 1 ) ) % 100019;



        if ( Hash_a1 == Hash1 && Hash_a2 == Hash2 ) r[++r[0]] = i - lg_a + 1;

    }



    fout << r[0] << '\n';

    r[0] = min ( 1000, r[0] );

    for ( i = 1 ; i <= r[0] ; i++ ) fout << r[i] << ' ';



    return 0;

}
