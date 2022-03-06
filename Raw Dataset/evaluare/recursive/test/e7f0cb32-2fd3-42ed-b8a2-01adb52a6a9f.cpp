#include <bits/stdc++.h>


using namespace std;



ifstream fin("evaluare.in") ;

ofstream fout("evaluare.out") ;



char sir[100005] ;

int i;



int termen() ;

int factor() ;



int eval()

{

    int r = termen() ;

    while ( sir[i] == '+' || sir[i] == '-' )

    {

        if ( sir[i] == '+' )

        {

            i++ ;

            r = r + termen() ;

        }

        else

        {

            i++ ;

            r = r-termen() ;

        }

    }

    return r;

}



int termen()

{

    int r = factor() ;

    while ( sir[i] == '*' || sir[i] == '/' )

    {

        if ( sir[i] == '*' )

        {

            i++ ;

            r = r*factor() ;

        }

        else

        {

            i++ ;

            r = r/factor() ;

        }

    }

    return r;

}



int factor()

{

    int r = 0 ;

    if ( sir[i] == '(' )

    {

        i++ ;

        r = eval() ;

        i++ ;

    }

    else

    {

        while ( sir[i] >='0' && sir[i] <= '9' )

        {

            r = r*10 + sir[i]-'0' ;

            i++ ;

        }

    }

    return r;

}



int main()

{

    fin >> sir ;

    i = 0 ;

    fout << eval() ;

}
