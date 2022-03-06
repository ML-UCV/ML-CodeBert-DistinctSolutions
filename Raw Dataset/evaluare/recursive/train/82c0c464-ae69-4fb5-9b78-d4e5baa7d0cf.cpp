#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream f ("evaluare.in");

ofstream g ("evaluare.out");

int ind;

char s[100005];

int f3();

int f2();

int f1()

{

    int result = f2();

    while(s[ind] == '+' or s[ind] == '-')

    {

        if(s[ind] == '+')

        {

            ++ind;

            result+=f2();

        }

        else

        {

            ++ind;

            result-=f2();

        }

    }

    return result;

}

int f2()

{

    int raspuns = f3();

    while(s[ind] == '*' or s[ind] == '/')

    {

        if(s[ind] == '*')

        {

            ++ind;

            raspuns*=f3();

        }

        else {

            ++ind;

            raspuns/=f3();

        }

    }

    return raspuns;

}

int f3()

{

    int raspuns=0;

    if(s[ind] == '(')

    {

        ++ind;

        raspuns = f1();

        ++ind;

    }

    else

    {

        while(isdigit(s[ind]))

        {

            raspuns = raspuns * 10 + (s[ind]-'0');

            ++ind;

        }

    }

    return raspuns;

}

int main()

{

    f.getline(s,100005);

    g<<f1();

    return 0;

}
