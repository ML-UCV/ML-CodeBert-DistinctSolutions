#include <bits/stdc++.h>


using namespace std;



ifstream in("evaluare.in");

ofstream out("evaluare.out");



string s;



int p = 0;



int priority(char k)

{

    if(k == '+' || k == '-')

        return 1;

    if(k == '*' || k == '/')

        return 2;

    return 3;

}



inline long long expresie();

inline long long termen();

inline long long factor();



long long expresie()

{

    long long t = termen();

    while(priority(s[p]) == 1)

    {

        if(s[p] == '+')

            ++p,t += termen();

        else

        if(s[p] == '-')

            ++p,t -= termen();

    }

    return t;



}



long long termen()

{

    long long t = factor();

    while(priority(s[p]) == 2)

    {

        if(s[p] == '*')

            ++p,t *= factor();

        else

        if(s[p] == '/')

            ++p,t /= factor();

    }

    return t;

}



long long factor()

{



    long long t = 0;



    if(s[p] == '(')

    {

        ++p;

        t = expresie();

        ++p;

    }

    else

    {

        while(s[p] >= '0' && s[p] <= '9')

        {

            t *= 10;

            t += s[p] - '0';

            ++p;

        }

    }

    return t;

}



int main()

{

    in >> s;

    out << expresie();



    return 0;

}
