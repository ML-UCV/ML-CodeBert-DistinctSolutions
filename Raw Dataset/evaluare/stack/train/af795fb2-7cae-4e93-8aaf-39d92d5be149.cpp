#include <bits/stdc++.h>


using namespace std;



ifstream fin( "evaluare.in" );

ofstream fout( "evaluare.out" );



string s;



deque <int> var;

deque <char> op;



void Read() {

    fin >> s;

    fin.close();

}



bool is_operator( char c ) {

    return strchr( "+-*/", c );

}



int Operate( int a, int b, char op ) {

    if( op == '+' ) return a + b;

    if( op == '-' ) return a - b;

    if( op == '*' ) return a * b;

    if( op == '/' ) return a / b;

}



int Priority( char ch ) {

    if( ch == '(' ) return 0;

    if( ch == '+' || ch == '-' ) return 1;

    if( ch == '/' || ch == '*' ) return 2;

}



void Do() {

    for( int i = 0; i < s.size(); ++i ) {

        if( s[i] == '(' ) { op.push_back( '(' ); continue; }

        if( isdigit( s[i] ) ) {

            int aux = 0;



            while( i < s.size() && isdigit( s[i] ) ) {

                aux = aux * 10 + s[i] - '0';

                ++i;

            }

            --i;



            var.push_back( aux );

            continue;

        }

        if( is_operator( s[i] ) ) {

            while( !op.empty() && Priority( op.back() ) >= Priority( s[i] ) ) {

                int a, b;

                char Op = op.back();



                op.pop_back();

                b = var.back(); var.pop_back();

                a = var.back(); var.pop_back();



                var.push_back( Operate( a, b, Op ) );

            }

            op.push_back( s[i] );

            continue;

        }

        if( s[i] == ')' ) {

          while( op.back() != '(' ) {

             int a, b;

             char Op = op.back();



             op.pop_back();

             b = var.back(); var.pop_back();

             a = var.back(); var.pop_back();



             var.push_back( Operate( a, b, Op ) );

          }

          op.pop_back();

        }



    }



    while( !op.empty() ) {

       int a, b;

       char Op = op.back();



       op.pop_back();

       b = var.back(); var.pop_back();

       a = var.back(); var.pop_back();



       var.push_back( Operate( a, b, Op ) );

    }



    fout << var.back() << '\n';

    fout.close();

}



int main()

{

    Read();

    Do();



    return 0;

}
