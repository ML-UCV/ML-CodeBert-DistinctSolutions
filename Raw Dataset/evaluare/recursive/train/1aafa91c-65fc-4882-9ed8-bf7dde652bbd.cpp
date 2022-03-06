#include <iostream>
#include <fstream>


using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");



int eval(),termen(),factor();



char *p;



int eval()

{

    int res=factor();

    cout<<res<<'\n';

    while(*p!='\00' && *p!=')')

    {

        int op=(*p=='+')? 1:0;

        ++p;

        int x=factor();

        cout<<x<<'\n';

        if(op)

            res+=x;

        else

            res-=x;

    }

    ++p;

    return res;

}



int factor()

{

    int t=termen();

    cout<<t<<'\n';

    while(*p=='*' || *p=='/')

    {

        int op=(*p=='*')? 1:0;

        ++p;

        int x=termen();

        cout<<x<<'\n';

        if(op)

            t*=x;

        else

            t/=x;



    }



    return t;

}



int termen()

{

    int t=0;

    if(*p=='(')

        ++p,t=eval();

    else

        while(*p>='0' && *p<='9')

            t=t*10+(*p-'0'),++p;

    return t;

}

int main()

{

    char s[100000];

    p=s;

    f>>s;

    g<<eval();



    return 0;

}
