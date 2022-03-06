#include <stack>
#include <string>
#include <cstdio>

using namespace std;

inline int app_op ( int x , int y , char op )
{
    if ( op == '+' ) return x + y ;
    if ( op == '-' ) return y - x ;
    if ( op == '*' ) return x * y ;
    if ( op == '/' ) return y / x ;
    return 0 ;
}

inline int priority ( char op )
{
    if ( op == '+' || op == '-' ) return 1 ;
    if ( op == '*' || op == '/' ) return 2 ;
    return 0 ;
}

void solve ( void )
{
    stack < char > operatori ;
    stack < int > operanzi ;
    char ch , op ;
    int nr = 0 , x1 , x2 , ok = 0 ;

    while ( scanf ( "%c" , & ch ) != EOF )
    {
        if ( isdigit ( ch ) )
            nr = nr * 10 + ( int ) ( ch - '0' ) , ok = 1 ;
        else
        {
            if ( ok )
            {
                operanzi.push ( nr ) ;
                nr = 0 ;
                ok = 0 ;
            }

            if ( ch == '(' )
                operatori.push ( '(' ) ;
            else
                if ( ch == ')' )
                {
                    while ( operatori.top () != '(' )
                    {
                        op = operatori.top () ; operatori.pop () ;
                        x1 = operanzi.top () ; operanzi.pop () ;
                        x2 = operanzi.top () ; operanzi.pop () ;

                        operanzi.push ( app_op ( x1 , x2 , op ) ) ;
                    }
                    operatori.pop () ;
                }
                else
                    if ( ch == '+' || ch == '-' || ch == '*' || ch == '/' )
                    {
                        while ( ! operatori.empty () && priority ( ch ) <= priority ( operatori.top () ) )
                        {
                            op = operatori.top () ; operatori.pop () ;
                            x1 = operanzi.top () ; operanzi.pop () ;
                            x2 = operanzi.top () ; operanzi.pop () ;

                            operanzi.push ( app_op ( x1 , x2 , op ) ) ;
                        }

                        operatori.push ( ch ) ;
                    }
        }
    }

    while ( ! operatori.empty () )
    {
        op = operatori.top () ; operatori.pop () ;
        x1 = operanzi.top () ; operanzi.pop () ;
        x2 = operanzi.top () ; operanzi.pop () ;

        operanzi.push ( app_op ( x1 , x2 , op ) ) ;
    }

    printf ( "%d" , operanzi.top () ) ;
}

int main()
{
    freopen ( "evaluare.in" , "r" , stdin ) ;
    freopen ( "evaluare.out" , "w" , stdout ) ;

    solve () ;

    return 0;
}
