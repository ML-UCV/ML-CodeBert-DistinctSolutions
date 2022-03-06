#include <bits/stdc++.h>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



char s[100005],*p=s;



int e2();

int e1()

{

    int r=e2();

    while(*p=='+' or *p=='-')

        if(*p=='+')

            p++, r+=e2();

        else

            p++, r-=e2();

    return r;

}

int e3();

int e2()

{

    int r=e3();

    while(*p=='*' or *p=='/')

        if(*p=='*')

            p++, r*=e3();

        else

            p++, r/=e3();

    return r;

}

int e3()

{

    int r=0;

    if(*p=='(')

        p++, r=e1(), p++;

    else

        while(*p>='0' and *p<='9')

            r=r*10+*p-'0', p++;

    return r;

}

int main()

{



    fin >> s;

    fout << e1();



    return 0;



}
