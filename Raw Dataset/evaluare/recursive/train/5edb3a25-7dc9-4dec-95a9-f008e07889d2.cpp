#include <bits/stdc++.h>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



long addOrSub();

long factor();

long term();



string input;

int position ;



long addOrSub()

{

    long result = factor();

    while (position < input.size() && (input[position] == '+' || input[position] == '-'))

    {

        if (input[position] == '+')

        {

            position++;

            result = result + factor();

        }

        else if (input[position] == '-')

        {

            position++;

            result = result - factor();

        }

    }

    return result;

}



long factor()

{

    long result = term();

    while (position < input.size() && (input[position] == '*' || input[position] == '/'))

    {

        if (input[position] == '*')

        {

            position++;

            result = result * term();

        }

        else if (input[position] == '/')

        {

            position++;

            result = result / term();

        }

    }

    return result;

}



long term()

{

    long result = 0;



    if (input[position] == '(')

    {

        position++;

        result = addOrSub();

        position++;

        return result;

    }

    else

    {

        long semn = 1;

        if (input[position] == '-')

        {

            position++;

            semn = -1;

        }



        while (position < input.size() && '0' <= input[position] && input[position] <= '9')

        {

            result = result * 10 + (input[position] - '0');

            position++;

        }

        result *= semn;

    }

    return result;

}



int main()

{

    fin >> input;

    fout << addOrSub();

    return 0;

}
