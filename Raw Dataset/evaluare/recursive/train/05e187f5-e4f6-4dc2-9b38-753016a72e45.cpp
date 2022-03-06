#include <cstdio>
#include <string>
#include <iostream>




using namespace std;



char s[100011];

char* p = s;



char peek()

{

    return* p;

}



char get()

{

    return *p++;

}



int termen()

{

    int result = get() - '0';

    while (peek() >= '0' && peek() <= '9')

    {

        result = result * 10 + (get() - '0');

    }

    return result;

}



int expression();



int factor()

{

    if (peek() >= '0' && peek() <= '9')

        return termen();

    else if (peek() == '(')

    {

        get();

        int result = expression();

        get();

        return result;

    }

    else if (peek() == '-')

    {

        get();

        return -factor();

    }

    return 0;

}



int term()

{

    int result = factor();

    while (peek() == '*' || peek() == '/')

    {

        if (get() == '*')

            result *= factor();

        else

            result /= factor();

    }

    return result;

}



int expression()

{

    int result = term();

    while (peek() == '+' || peek() == '-')

    {

        if (get() == '+')

            result += term();

        else

            result -= term();

    }

    return result;

}



int main()

{

    if(fgets(s, 100011, fopen("evaluare.in", "r")) != NULL);

        fprintf(fopen("evaluare.out", "w"), "%d\n", expression());

    return 0;

}
