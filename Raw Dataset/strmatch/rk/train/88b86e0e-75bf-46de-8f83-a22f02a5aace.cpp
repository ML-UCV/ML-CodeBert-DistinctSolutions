#include <bits/stdc++.h>
using namespace std;



ifstream fin ("strmatch.in");

ofstream fout ("strmatch.out");



vector < int > R;

char a[2000005], b[2000005];



int main()

{

    int lg_a, lg_b, i, hash1a = 0, hash2a = 0, hash1 = 0, hash2 = 0, P1 = 1, P2 = 1, nr;



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

        hash1a = ( hash1a * 80 + a[i] - '0' + 1 ) % 45007;

        hash2a = ( hash2a * 80 + a[i] - '0' + 1 ) % 45013;



        hash1 = ( hash1 * 80 + b[i] - '0' + 1 ) % 45007;

        hash2 = ( hash2 * 80 + b[i] - '0' + 1 ) % 45013;



        if ( i != 0 ) P1 = ( P1 * 80 ) % 45007, P2 = ( P2 * 80 ) % 45013;

    }



    if ( hash1a == hash1 && hash2a == hash2 ) R.push_back ( 0 );

    for ( i = lg_a ; i < lg_b ; i++ )

    {

        hash1 = ( ( hash1 - ( P1 * ( b[i-lg_a] - '0' + 1 ) ) % 45007 + 45007 ) * 80 + b[i] - '0' + 1 ) % 45007;

        hash2 = ( ( hash2 - ( P2 * ( b[i-lg_a] - '0' + 1 ) ) % 45013 + 45013 ) * 80 + b[i] - '0' + 1 ) % 45013;



        if ( hash1 == hash1a && hash2 == hash2a ) R.push_back ( i - lg_a + 1 );

    }



    fout << R.size() << '\n';

    nr = R.size();

    nr = min ( nr, 1000 );

    for ( i = 0 ; i < nr ; i++ ) fout << R[i] << ' ';



    return 0;

}
