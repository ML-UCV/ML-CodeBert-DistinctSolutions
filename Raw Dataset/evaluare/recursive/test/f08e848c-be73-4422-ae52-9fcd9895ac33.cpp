#include <bits/stdc++.h>
using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");



char *p,e[1<<17];



int eval(),termen(),factor();



int main()

{ f.get(e,1<<17);

    p=e;

    g<<eval();

    g.close(); return 0;

}



int eval()

{ int r=termen();

    for(; *p=='+' || *p=='-'; *(p-1)=='+' ? r+=termen() : r-=termen())

        p++;

    return r;

}



int termen()

{ int r=factor();

    for(; *p=='*' || *p=='/'; *(p-1)=='*' ? r*=factor() : r/=factor())

        p++;

    return r;

}



int factor()

{ int r;

    if(*p=='(')

    { p++;

        r=eval();

        p++;

    }

    else

    { int nr;

        for(nr=0; *p>='0' && *p<='9'; p++)

            nr=nr*10+(*p-'0');

        r=nr;

    }

    return r;

}
