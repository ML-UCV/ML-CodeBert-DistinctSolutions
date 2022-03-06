#include <fstream>


using namespace std;



const int N=100010;

char s[N],*p=s;



typedef long long int lli;



lli factor(),termen();



lli eval()

{

    lli r=termen();

    while(*p=='+' || *p=='-')

    {

        if(*p=='+')

        {

            p++;

            r+=termen();

        }else{

            p++;

            r-=termen();

        }

    }

    return r;

}



lli termen()

{

    lli r=factor();

    while(*p=='*' || *p=='/')

    {

        if(*p=='*')

        {

            p++;

            r*=factor();

        }else{

            p++;

            r/=factor();

        }

    }

    return r;

}





lli factor()

{



    lli r=0;

    if(*p=='(')

    {

        p++;

        r=eval();

        p++;

    }else{

        while(*p>='0' && *p<='9')

        {

            r=r*10+*p-'0';

            p++;

        }

    }

    return r;

}



int main()

{

    freopen("evaluare.in","r",stdin);

    freopen("evaluare.out","w",stdout);

    fgets(s,N,stdin);

    printf("%ld\n",eval());

    return 0;

}
