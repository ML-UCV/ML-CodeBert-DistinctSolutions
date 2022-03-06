#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>


using namespace std;



const int NMAX = 2000005;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



char P[NMAX], S[NMAX];

int LPS[NMAX];

vector < int > Sol;



void lps()

{

    LPS[0]=0;



    for( int i = 1; P[i]; ++i )

        if( P[i] == P[LPS[i-1]] )

            LPS[i] = LPS[i-1]+1;

        else

        {

            int p = LPS[i-1];



            while( p!= 0 && P[i] != P[p] )

                p = LPS[p-1];



            if( P[i] == P[p] )LPS[i] = p+1;

        }

}

void Solve()

{

     fin >> P >> S;

     int np = strlen( P ), k = 0;

     lps();







     for( int i = 0; S[i]; ++i )

     {



         if( S[i] == P[k] )

         {

             k++;

             if( k == np )

             {

                 Sol.push_back( i - np + 1 );

                 k = LPS[k-1];

             }

         }

         else

         {

             if( k )

             {

                 k = LPS[k-1];

                 i--;

             }

         }

     }



     fout << Sol.size() << '\n';



     for( int i = 0; i < Sol.size() && i < 1000; ++i )

        fout << Sol[i] << ' ';

}

int main()

{

    Solve();



    return 0;

}
