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



    for ( int i = 0; i < lng; i++ )

    {

        if ( cuvant[i] == pat[j] )

        {

            if ( j == lg-1 )

            {

                k++;

                if ( k <= 1000)

                    sol.push_back(i-j);



                j = v[j];

            }



            else

                j++;

        }



        else

        {

            while ( j && pat[j]!= cuvant[i] )

                j = v[j-1];



            if ( pat[j] == cuvant[i] )

                j++;



        }

    }

}



void preprocess ( )

{

    int lng = pat.size();

    v.reserve ( lng+1 );



    v[0] = 0;



    int j = 0;



    for ( int i = 1; i < lng; i++ )

    {

        if ( pat[j] == pat[i] )

        {

            v[i] = j + 1;

            j++;

        }



        else

        {

            while ( j && pat[j] != pat[i] )

                j = v[j-1];



            if ( pat[j] == pat[i] )

            {

                v[i] = j + 1 ;

                j++;

            }



            else

                v[i] = 0;

        }

    }

}



void read ( )

{

    getline ( fin, pat );

    getline ( fin, cuvant );

}
