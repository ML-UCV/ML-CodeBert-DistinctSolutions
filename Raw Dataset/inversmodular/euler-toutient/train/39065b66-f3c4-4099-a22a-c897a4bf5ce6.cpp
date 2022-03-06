#include <iostream>
#include <fstream>


using namespace std;



int phi( int n ) {

    int d = 2, val, rez = 1;

    while ( d * d <= n ) {

        val = 1;

        while ( n % d == 0 ) {

            val *= d;

            n /= d;

        }

        if ( val > 1 )

            val = val / d * ( d - 1 );

        rez *= val;

        d ++;

    }

    if ( n > 1 )

        rez *= n - 1;

    return rez;

}



int exponentiere( long long b, int e, int mod ) {

    long long produs = 1;

    while ( e > 0 ) {

        if ( e % 2 == 0 ) {

            b = b * b % mod;

            e /= 2;

        } else {

            produs = produs * b % mod;

            e --;

        }

    }

    return produs;

}

int main() {

    ifstream fin( "inversmodular.in" );

    ofstream fout( "inversmodular.out" );

    int n, mod, e, i;

    fin >> n >> mod;

    e = phi( mod ) - 1;

    fout << exponentiere( n, e, mod ) << endl;

    fout.close();

    fin.close();

    return 0;

}
