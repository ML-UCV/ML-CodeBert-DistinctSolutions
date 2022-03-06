#include <fstream>
#include <cstring>


using namespace std;

ifstream f("swap.in");

ofstream g("swap.out");

int n,i,lga,lgb,s,ok;

int APa[300];

int APb[300];

int ord[50005];

int poz[300][50005];

int c[50005];

char a[50005];

char b[50005];

int p[50005];

void update(int poz, int val)

{

    int i;

    for(i=poz;i<=n;i+=( (-i)&i ))

    {

        c[i]+=val;

    }

}

int sum(int poz)

{

    int i,s;

    s=0;

    for(i=poz;i>=1;i-=( (-i)&i ))

    {

        s+=c[i];

    }

    return s;

}

int main()

{

    f.getline(a,50005);

    f.getline(b,50005);



    lga=strlen(a);

    for(i=0;i<lga;++i)

    {

        ++APa[a[i]];

        ord[i]=APa[a[i]];

    }

    lgb=strlen(b);

    for(i=0;i<lgb;++i)

    {

        ++APb[b[i]];



        poz[b[i]][APb[b[i]]]=i+1;

    }

    ok=0;

    for(i='a';i<='z' && !ok;++i) if(APa[i]!=APb[i]) ok=1;

    if(ok==1) g<<"-1"<<'\n';

    else

    {

        for(i=0;i<lga;++i)

        {

            p[i+1]=poz[a[i]][ord[i]];

        }







        n=lga;

        for(i=n;i>=1;--i)

        {

            s+=sum(p[i]);

            update(p[i],1);

        }

        g<<s<<'\n';

    }

    return 0;

}
