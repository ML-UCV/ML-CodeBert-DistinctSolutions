#include <fstream>

using namespace std;

ifstream cin("evaluare.in");
ofstream cout("evaluare.out");

const int dim = 100005;

int current;
char a[dim];

int evaluare();
int termen();
int factor();

bool isOp1(char c)
{
    return (c == '+' || c == '-');
}


bool isOp2(char c)
{
    return (c == '*' || c == '/');
}

bool isDigit(char c)
{
    if(c >= '0' && c <='9')
        return true;
    return false;
}

int getSign(char c)
{
    if(c == '-')
        return -1;
    else if(c == '+')
        return 1;
    return 0;
}

int getDigit(char c)
{
    return c - '0';
}

int evaluare()
{
    int rez = termen(), sign = 0;
    while((sign = getSign(a[current])) != 0)
    {
        current++;
        rez += sign * termen();
    }
    return rez;
}

int termen()
{
    int rez = factor();
    while(isOp2(a[current]))
    {
        if(a[current] == '*')
            current++, rez *= factor();
        else if(a[current] == '/')
            current++, rez /= factor();
    }
    return rez;
}

int factor()
{
    int rez = 0, sign = 1;
    while(a[current] == '-')
    {
        current++;
        sign *= -1;
    }

    if(a[current] == '(')
    {
        current++;
        rez = evaluare();
        current++;
        return rez * sign;
    }

    while(isDigit(a[current]))
    {
        rez = rez * 10 + getDigit(a[current]);
        current++;
    }

    return rez * sign;
}

int main()
{
    cin>>a;
    int rez = evaluare();

   cout<<rez;
    return 0;
}
