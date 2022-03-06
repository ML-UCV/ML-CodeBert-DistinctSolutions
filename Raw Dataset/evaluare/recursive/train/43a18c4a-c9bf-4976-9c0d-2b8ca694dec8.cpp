#include <fstream>


using namespace std;



ifstream cin ("evaluare.in");

ofstream cout ("evaluare.out");



char s[100010];

int poz;



char peek()

{

    return s[poz];

}



char pop()

{

    return s[poz++];

}



int solve();



int getFact()

{

    int result = 0;

    if( peek() == '(' )

    {

        pop();

        result = solve();

        pop();

        return result;

    }

    while( peek() >= '0' && peek() <= '9' )

        result = result * 10 + pop() - '0';

    return result;

}



int getTerm()

{

    int fact1 = getFact();

    while( peek() == '*' || peek() == '/' )

        if( pop() == '*' )

            fact1 *= getFact();

        else

            fact1 /= getFact();

    return fact1;

}



int solve()

{

    int term1 = getTerm();

    while( peek() == '-' || peek() == '+' )

        if( pop() == '-' )

            term1 -= getTerm();

        else

            term1 += getTerm();

    return term1;

}



int main()

{

    cin >> s;

    cout << solve();

    return 0;

}
