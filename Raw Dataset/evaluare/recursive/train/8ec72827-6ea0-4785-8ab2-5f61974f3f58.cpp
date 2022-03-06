#include <bits/stdc++.h>




using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");

char s[100005],*p;

int eval();

int termen();

int factor();

int numar()

{ int nr=0;

    while(*p>='0' && *p<='9')

    { nr=nr*10+*p-48;

        p++;

    }

    return nr;

}

int main()

{ f>>s;

    p=s;

    g<<eval();

}

int eval()

{ int r=termen();

    while(*p=='+' || *p=='-')

    { if(*p=='+')

        { p++;

            r+=termen();

        }

        else

        if(*p=='-')

        { p++;

            r-=termen();

        }

    }

    return r;

}

int termen()

{ int r=factor();

    while(*p=='*' || *p=='/')

    { if(*p=='*')

        { p++;

            r*=factor();

        }

        else

        if(*p=='/')

        { p++;

            r/=factor();

        }

    }

    return r;

}

int factor()

{ int r;

    if(*p=='(')

    { p++;

        r=eval();

        p++;

    }

    else r=numar();

    return r;

}
