#include <bits/stdc++.h>


using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



string s;

int x;



bool op1(int ind)

{

    if(s[ind]=='+' || s[ind]=='-')

        return 1;

    else

        return 0;

}



bool op2(int ind)

{

    if(s[ind]=='*' || s[ind]=='/')

        return 1;

    else

        return 0;

}



int factor(int &ind)

{

    int eval(int &a);

    int nr=0;

    if(s[ind]=='(')

    {

        int nr=eval(++ind);

        ind++;

        return nr;

    }

    else

        while(ind<=s.size() && isdigit(s[ind]))

    {

        nr=nr*10+s[ind]-'0';

        ind++;

    }

    return nr;

}



int termen(int &ind)

{

    int p=factor(ind);

    while(ind<=s.size() && op2(ind))

    {

        if(s[ind]=='*')

            p*=factor(++ind);

        else

            p/=factor(++ind);

    }

    return p;

}



int eval(int &ind)

{

    int a=termen(ind);

    while(ind<=s.size() && op1(ind))

    {

        if(s[ind]=='+')

            a+=termen(++ind);

        else

            a-=termen(++ind);

    }

    return a;

}



int main()

{

    fin>>s;

    fout<<eval(x);

    return 0;

}
