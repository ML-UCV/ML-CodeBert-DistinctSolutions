#include <bits/stdc++.h>






using namespace std;



ifstream fin ("evaluare.in");

ofstream fout ("evaluare.out");



int indexx = 0;



char S[1 + 100000 + 5];



int math ();



int fact ()

{

    int integer = 0, sign = 1;

    if (S[indexx] == '-')

        ++indexx, sign = -1;

    if (S[indexx] == '(')

    {

        ++indexx;

        integer = math ();

        ++indexx;

    }

    else while (isdigit (S[indexx]))

            integer = integer * 10 + S[indexx] - '0', ++indexx;

    return sign * integer;

}



int term ()

{

    int sum = fact ();

    while (S[indexx] == '*' || S[indexx] == '/')

        if (S[indexx++] == '*')

            sum *= fact ();

        else

            sum /= fact ();

    return sum;

}



int math ()

{

    int sum = term ();

    while (S[indexx] == '+' || S[indexx] == '-')

        if (S[indexx++] == '+')

            sum += term ();

        else

            sum -= term ();

    return sum;

}



int main()

{

    fin >> S;

    fout << math ();

    return 0;

}
