#include <fstream>


using namespace std;



ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");



struct A

{

    long long nr_prim, exponent;

};



A v[15];

long long MOD;



long long n_la_puterea_k ( long long n, long long k );

long long indicator_Euler ( long long x );



int main()

{

    long long a;



    fin >> a >> MOD;

    fout << ( n_la_puterea_k ( a, indicator_Euler ( MOD ) - 1 ) ) % MOD;



    return 0;

}



long long n_la_puterea_k ( long long n, long long k )

{

    if ( k == 0 ) return 1;

    else if ( k == 1 ) return n % MOD;

    else if ( k % 2 == 0 ) return ( n_la_puterea_k ( ( n * n ) % MOD, k / 2 ) ) % MOD;

    else return ( n * n_la_puterea_k ( ( n * n ) % MOD, k / 2 ) ) % MOD;

}



long long indicator_Euler ( long long x )

{

    long long i, rez = 1;



    if ( x % 2 == 0 )

    {

        v[++v[0].exponent].nr_prim = 2;

        while ( x % 2 == 0 )

        {

            x /= 2;

            v[v[0].exponent].exponent++;

        }

    }



    for ( i = 3 ; i * i <= x ; i += 2 )

        if ( x % i == 0 )

        {

            v[++v[0].exponent].nr_prim = i;

            while ( x % i == 0 )

            {

                x /= i;

                v[v[0].exponent].exponent++;

            }

        }



    if ( x != 1 ) v[++v[0].exponent].nr_prim = x, v[v[0].exponent].exponent = 1;



    for ( i = 1 ; i <= v[0].exponent ; i++ ) rez *= ( v[i].nr_prim - 1 ) * n_la_puterea_k ( v[i].nr_prim, v[i].exponent - 1 );



    return rez;

}
