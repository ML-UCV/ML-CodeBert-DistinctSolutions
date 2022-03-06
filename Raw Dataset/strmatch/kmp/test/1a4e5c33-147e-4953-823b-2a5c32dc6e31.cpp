#include <bits/stdc++.h>
using namespace std;

ifstream fin ( "strmatch.in" );

ofstream fout ( "strmatch.out" );



void read ( );

void preprocess ( );

void solve ( );

void afis ( );



string pat;

string cuvant;



vector < int > v;

vector < int > sol;



int k;



int main ( )

{

    read ( );



    preprocess ( );



    solve ( );



    afis ( );

}



void afis ( )

{

    fout << k << '\n';



    int lng = sol.size();



    for ( int i = 0; i < lng; i++ )

        fout << sol[i] << ' ';



    exit ( 0 );

}



void solve ( )

{

    int lng = cuvant.size();

    int lg = pat.size();



    int j = 0;

    int i = 0;



    while ( i < lng )

    {

        if ( pat[j] == cuvant[i] )

        {

            i++;

            j++;

        }



        if ( j == lg )

        {

            k++;

            if ( k <= 1000 )

            sol.push_back ( i - j );

            j = v[lg-1];

        }



        else if ( i < lng && pat[j] != cuvant[i] )

        {

            if ( j )

                j = v[j-1];

            else

                i++;

        }

    }

}



void preprocess ( )

{

    int lng = pat.size();

    v.reserve ( lng+1 );



    v[0] = 0;



    int len = 0;

    int i = 1;



    while ( i < lng )

    {

        if ( pat[i] == pat[len] )

        {

            len++;

            v[i] = len;

            i++;

        }



        else

        {

            if ( len )

                len = v[len-1];

            else

            {

                v[i] = 0;

                i++;

            }

        }

    }

}



void read ( )

{

    getline ( fin, pat );

    getline ( fin, cuvant );

}
