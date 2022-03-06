#include <cstdio>


using namespace std;

FILE *f,*g;



void inv(long long a,long long b,long long &x,long long &y)

{

    if(!b)

        x=1,y=0;

    else

    {

        inv(b,a%b,x,y);

        int aux=x;

        x=y;

        y=aux-a/b*y;

    }

}

int main()

{

    f=fopen("inversmodular.in","r");

    g=fopen("inversmodular.out","w");

    long long nr,mod,x,y;

    fscanf(f,"%lld %lld",&nr,&mod);

    inv(nr,mod,x,y);

    if(x<=0)

        x=mod+x%mod;

    fprintf(g,"%lld\n",x);

    fclose(f);

    fclose(g);

    return 0;

}
