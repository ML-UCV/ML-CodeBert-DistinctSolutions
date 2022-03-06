#include <bits/stdc++.h>


using namespace std;



const int NMAX = 100004;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



stack < int > S;

stack < char > Op;



char C[NMAX];



int pi = 2000000000, x;

int pl = pi+1;

int m = pi-1;

int sup = pi-2;

int ori = pi+2;

int N;



int NR( int &i )

{

    int nr = 0;

    while( C[i] >= '0' && C[i] <= '9' )

    {

        nr = nr*10 + C[i]-'0';

        i++;

    }

    i--;

    return nr;

}



int Priority( char op )

{

    if( op == '*' || op == '/' )

        return 2;

    if( op == '+' || op == '-' )

        return 1;

    return 0;

}



int ApplyOp( int x, int y, char op )

{

    switch( op )

    {

        case '+': return x+y;

        case '-': return x-y;

        case '*': return x*y;

        case '/': return x/y;

    }

}

void Solve()

{

    fin >> C;

    N = strlen( C );



    for( int i = 0; C[i]; ++i )

    {



        if( C[i] == '(' )

        {

            Op.push( C[i] );

            continue;

        }

        if( C[i] >= '0' && C[i] <= '9' )

            S.push( NR( i ) );



        else

        if( C[i] == ')' )

        {

            while( Op.size() && Op.top() != '(' )

            {

                int val1 = S.top();S.pop();

                int val2 = S.top();S.pop();





                S.push( ApplyOp( val2, val1, Op.top() ) );

                Op.pop();

            }

            if( Op.size() ) Op.pop();



        }

        else

        {

            while( Op.size() && Priority( Op.top() ) >= Priority( C[i] ) )

            {

                int val1 = S.top();S.pop();

                int val2 = S.top();S.pop();



                S.push( ApplyOp( val2, val1, Op.top() ) );



                Op.pop();

            }

            Op.push( C[i] );

        }

    }

    while( Op.size() && Op.top() != '(' )

    {

        int val1 = S.top();S.pop();

        int val2 = S.top();S.pop();



        S.push( ApplyOp( val2, val1, Op.top() ) );

        Op.pop();

    }

    if( Op.size() ) Op.pop();

        fout << S.top();

}

int main()

{

    Solve();

    return 0;

}
