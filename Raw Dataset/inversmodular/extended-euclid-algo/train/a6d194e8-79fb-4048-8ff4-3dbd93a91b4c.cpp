#include <cstdio>


FILE* FIN=freopen("inversmodular.in","r",stdin);

FILE* FOUT=freopen("inversmodular.out","w",stdout);



long long n,m;



void cit()

{

    scanf("%lld%lld",&n,&m);

}

void invmod(long long &x,long long &y,long long z,long long t)

{

    if(!t)

    {

        x=1;

        y=0;

    }

    else

    {

        int b;

        invmod(x,y,t,z%t);

        b=x;

        x=y;

        y=b-y*(z/t);

    }

}

void af(long long p)

{

    p%=m;

    p+=(p<0)*m;

    printf("%lld",p);

}

int main()

{

    long long p=0,k;

    cit();

    invmod(p,k,n,m);

    af(p);

    return 0;

}
