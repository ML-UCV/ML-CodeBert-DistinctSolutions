#include <iostream>
#include <stack>
#include <string.h>
#include <stdio.h>
#include <fstream>
using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

stack<char> stac;

bool isPriority(char a,char b)

{

    if((b=='+' || b=='-') && (a=='*' || a=='/'))

        return true;

    if((b=='+' || b=='-') && (a=='+' || a=='-'))

        return true;

    if((b=='*' || b=='/') && (a=='*' || a=='/'))

        return true;

    return false;

}

bool isDigit(char a)

{

    if(a>='0'&& a<='9')

        return true;

    return false;

}

string infixToPostFix(string a)

{

    string res;

    for(int i = 0; i< a.size(); i++)

    {

        if(isDigit(a[i]))

        {

            res+=a[i];

            if(i!=a.size()-1)

            {

                if(!isDigit(a[i+1]))

                    res+=" ";

            }

            else

            {

                res+=" ";

            }

        }

        else

        {

            if(a[i]==')')

            {

                while(stac.size() && stac.top()!='(')

                    res+=stac.top(),stac.pop();

                if(stac.size())

                    stac.pop();

            }

            else

            {

                while(stac.size() && isPriority(stac.top(),a[i]))

                {

                    res+=stac.top();

                    stac.pop();

                }

                stac.push(a[i]);

            }

        }

    }

    while(stac.size())

            res+=stac.top(),stac.pop();

    return res;

}

stack<long long> numere;

long long solvePostFix(string a)

{

    long long b=0;

    for(int i = 0;i<a.size();i++)

    {

        if(isDigit(a[i]))

            b*=10,b+=((int)a[i]-(int)'0');

        else if(a[i]==' ')

            numere.push(b),b=0;

        else

        {

            long long num1,num2,res=0;

            num1=numere.top();

            numere.pop();

            num2=numere.top();

            numere.pop();

            switch(a[i])

            {

                case '+':

                    res = num1+num2;

                    break;

                case '-':

                    res = num2-num1;

                    break;

                case '/':

                    res = num2/num1;

                    break;

                case '*':

                    res = num1*num2;

                    break;

            }

            numere.push(res);

        }

    }

    return numere.top();

}

int main()

{

    string a;

    fin>>a;

    fout<<solvePostFix(infixToPostFix(a))<<'\n';

    return 0;

}
