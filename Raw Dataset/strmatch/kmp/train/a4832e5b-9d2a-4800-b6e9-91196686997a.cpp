#include <bits/stdc++.h>


using namespace std;



ifstream fin( "strmatch.in" );

ofstream fout( "strmatch.out" );



const int NMAX = 2000005;



string A, pat;

int lps[NMAX];



void Read() {

    fin >> pat >> A;

}



void Lps()

{

    int lg = 0;



    for( int i = 1; i < pat.size(); ++i )

       if( pat[i] == pat[lg] ) lps[i] = ++lg;

       else

         if( lg > 0 ) {

            lg = lps[lg - 1];

            --i;

         }

}



void Do()

{

    Lps();



    int nr = 0;

    int i, j;

    vector <int> pos;



    i = j = 0;



    while( i < A.size() ) {

       if( A[i] == pat[j] ) {

         ++i;

         ++j;

       }



       if( j == pat.size() ) {

         ++nr;

         if( pos.size() < 1000 ) pos.push_back( i - j );



         j = lps[j - 1];

       }

       else

         if( i < A.size() && pat[j] != A[i] )

           if( j > 0 ) j = lps[j - 1];

           else ++i;

    }



    fout << nr << '\n';



    for( int i = 0; i < pos.size(); ++i )

       fout << pos[i] << ' ';

}



int main()

{

    Read();

    Do();



    return 0;

}
