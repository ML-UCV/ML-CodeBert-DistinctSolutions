#include <bits/stdc++.h>


using namespace std;



ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");



struct A

{

    int nr, val;

};



vector < A > v;

int MOD;



long long n_la_puterea_k ( long long n, long long k );

long long indicator_Euler ( long long x );



int main()

{

    long long x;



    fin >> x >> MOD;

    fout << n_la_puterea_k ( x, indicator_Euler ( MOD ) - 1 );



    return 0;

}



long long n_la_puterea_k ( long long n, long long k )

{

    if ( k == 0 ) return 1;

    else if ( k == 1 ) return n % MOD;

    else if ( k % 2 == 0 ) return n_la_puterea_k ( ( n * n ) % MOD, k / 2 );

    else return ( ( n % MOD ) * n_la_puterea_k ( ( n * n ) % MOD, k / 2 ) ) % MOD;

}



long long indicator_Euler ( long long x )

{

    long long i, nr, val, r = 1;



    if ( x % 2 == 0 )

    {

        nr = 2, val = 0;

        while ( x % 2 == 0 ) val++, x /= 2;

        v.push_back ( { nr, val } );

    }



    for ( i = 3 ; i * i <= x ; i += 2 )

        if ( x % i == 0 )

        {

            nr = i, val = 0;

            while ( x % i == 0 ) val++, x /= i;

            v.push_back ( { nr, val } );

        }



    if ( x != 1 ) v.push_back ( { x, 1 } );

    for ( i = 0 ; i < v.size() ; i++ ) r *= ( v[i].nr - 1 ) * n_la_puterea_k ( v[i].nr, v[i].val - 1 );



    return r;

}
