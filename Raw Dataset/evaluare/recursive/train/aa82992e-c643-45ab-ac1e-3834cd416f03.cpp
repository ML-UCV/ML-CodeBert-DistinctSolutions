#include <bits/stdc++.h>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



char s[100005],*p=s;



long e1();

long e2();

long e()

{

    long r=e1();

    while(*p=='+' or *p=='-')

        if(*p=='+')

            ++p, r+=e1();

        else

            ++p, r-=e1();

    return r;

}

long e1()

{

    long r=e2();

    while(*p=='*' or *p=='/')

        if(*p=='*')

            ++p, r*=e2();

        else

            ++p, r/=e2();

    return r;

}

long e2()

{

    long r=0;

    if(*p=='(')

        ++p, r=e(), ++p;

    else

        while(*p>='0' and *p<='9')

            r=r*10+*p-'0', ++p;

    return r;

}



int main()

{



    fin >> s;

    fout << e();



    return 0;



}
