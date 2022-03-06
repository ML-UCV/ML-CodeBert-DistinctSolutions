#include <bits/stdc++.h>
using namespace std;

ifstream f ( "evaluare.in" );

ofstream g ( "evaluare.out" );

char s[100005],*p;



int expresii();

int factori()

{ int r=0;

    if(*p=='(')

    { ++p;

        r=expresii();

        ++p;

    }

    else

    { while(*p>='0' and *p<='9')

        { r=r*10+*p-'0';

            ++p;

        }

    }

    return r;

}

int termeni()

{ int r=factori();

    while(*p=='*' || *p=='/' )

    { if(*p=='*')

        { ++p;

            r*=factori();

        }

        if(*p=='/')

        { ++p;

            r/=factori();

        }

    }

    return r;

}

int expresii()

{ int r=termeni();

    while(*p=='+' || *p=='-')

    { if(*p=='+')

        { ++p;

            r+= termeni();

        }

        else if (*p=='-')

        { ++p;

            r-= termeni();

        }

    }

    return r;

}

int main()

{ f>>s;

    p=s;

    g<<expresii();

    return 0;

}
