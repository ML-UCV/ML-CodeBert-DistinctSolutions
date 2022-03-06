#include <bits/stdc++.h>


using namespace std;



ifstream fin ( "inversmodular.in" );

ofstream fout ( "inversmodular.out" );



void invers_mod ( int a, int b, int &x, int &y );



int main ( )

{

    int a, mod;



    fin >> a >> mod;



    int x, y;



    invers_mod( a, mod, x, y);



    while ( x < 0 )

        x += mod;

    fout << x << '\n' ;

}





void invers_mod ( int a, int b, int &x, int &y )

{

    if ( b == 0 )

    {

        x = 1;

        y = 0;



        return ;

    }



    int c = a/b;



    invers_mod ( b, a%b, x, y );



    int x1 = y;

    int y1 = x - y*c;



    y = y1;

    x = x1;

}
