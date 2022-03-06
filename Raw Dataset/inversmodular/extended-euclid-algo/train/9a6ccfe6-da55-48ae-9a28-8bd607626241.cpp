#include <cstdio>


using namespace std;

FILE *f,*g;



void im(long long a, long long b, long long &x, long long &y)

{

    if(!b)

        x=1,y=0;

    else

    {

        im(b,a%b,x,y);

        int cop=x;

        x=y;

        y=cop-a/b*y;

    }

}

int main()

{

    f=fopen("inversmodular.in","r");

    g=fopen("inversmodular.out","w");

    long long a,mod,x,y;

    fscanf(f,"%lld %lld",&a,&mod);

    im(a,mod,x,y);

    if(x<=0)

        x=mod+x%mod;

    fprintf(g,"%lld",x);

    fclose(f);

    fclose(g);

    return 0;

}
