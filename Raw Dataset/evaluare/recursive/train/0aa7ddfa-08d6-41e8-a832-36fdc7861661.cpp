#include <fstream>


using namespace std;



ifstream in ("evaluare.in");

ofstream out ("evaluare.out");



int solve ();



int term ();



int fact ();



char s[100137];



int poz;



int main()

{

    in >> s;

    out << solve ();

    return 0;

}



int solve ()

{

    int nr = term ();

    while ( s[poz] == '-' || s[poz] == '+' )

        if ( s[poz] == '+' )

        {

            ++poz;

            nr += term ();

        }

        else

        {

            ++poz;

            nr -= term ();

        }

    return nr;

}



int term ()

{

    int nr = fact();

    while ( s[poz] == '*' || s[poz] == '/' )

        if ( s[poz] == '*' )

        {

            ++poz;

            nr *= fact();

        }

        else

        {

            ++poz;

            nr /= fact();

        }

    return nr;

}



int fact ()

{

    int nr = 0;

    if ( s[poz] == '(' )

    {

        ++poz;

        nr = solve();

        ++poz;

        return nr;

    }

    while ( s[poz] >= '0' && s[poz] <= '9' )

        {

            nr = nr * 10 + s[poz] - '0';

            ++poz;

        }

    return nr;

}
