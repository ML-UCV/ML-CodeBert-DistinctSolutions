#include <bits/stdc++.h>
using namespace std;

ifstream fin( "strmatch.in" );

ofstream fout( "strmatch.out" );

void fast()

{

    cin.tie( 0 );

    ios_base::sync_with_stdio( 0 );

}

vector<int>sol;

string a, b;

long long lps[2000005];

void calc_lps()

{

    long long len = 0;

    int n = a.size();



    for( int i = 1; i < n; i++ )

        {

            while( a[i] != a[len] && len )

                len = lps[len - 1];



            if( a[len] == a[i] )

                len++;



            lps[i] = len;

        }

}

int main()

{

    fast();

    fin >> a >> b;

    calc_lps();
    long long len = 0;

    int n = b.size();



    for( int i = 0; i < n; i++ )

        {

            while( a[len] != b[i] && len )

                len = lps[len - 1];



            if( a[len] == b[i] )

                len++;



            if( len == a.size() )

                sol.push_back( i - len + 1 );



        }



    fout << sol.size() << '\n';



    for( int i = 0; i < min( 1000,(int)(sol.size()) ); i++ )

        fout << sol[i] << ' ';



    return 0;

}
