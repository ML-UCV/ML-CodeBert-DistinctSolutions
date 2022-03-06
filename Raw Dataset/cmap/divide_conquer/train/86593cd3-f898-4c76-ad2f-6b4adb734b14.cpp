#include <iostream>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<algorithm>
using namespace std;



long double dm,a,b,c,l;

long long x[100001],y[100001],v[100001],w[100001];

int I[100001],i,k,j,ls,ld,m,n,u;

long double D(long long a,long long b,long long c,long long d)

{

    return sqrt( (a-c)*(a-c) + (b-d)*(b-d) );

}

bool compare(int i,int j)

{

    if(x[i]==x[j])

        return(y[i]<y[j]);

    return (x[i]<x[j]);

}

void sol(int ls,int ld,long double &dm)

{

    if(ld-ls==1)

    {

        long double a=D(x[I[ls]],y[I[ls]],x[I[ld]],y[I[ld]]);

        dm=min(dm,a);

        return ;

    }

    if(ld-ls==2)

    {

        long double a=D(x[I[ls]],y[I[ls]],x[I[ld]],y[I[ld]]);

        long double b=D(x[I[ls]],y[I[ls]],x[I[ld-1]],y[I[ld-1]]);

        a=min(a,b);

        b=D(x[I[ls+1]],y[I[ls+1]],x[I[ld]],y[I[ld]]);

        a=min(a,b);

        dm=min(dm,a);

        return ;

    }

    int m=(ls+ld+1)/2;

    sol(ls,m,dm);

    sol(m,ld,dm);

    int k=0;

    int o=x[I[m]];

    for(int i=ls;i<=ld;++i)

    {

        if(abs( o - x[ I[i] ] ) < dm )

        {

            v[++k]=x[I[i]];

            w[k]=y[I[i]];

        }

    }

    int p;

    long double a;

    for(i=1;i<k;++i)

    {

        p=min(i+8,k+1);

        for(j=i+1;j<p;++j)

        {

            a=D(v[i],w[i],v[j],w[j]);

            dm=min(dm,a);

        }

    }

}

int main()

{

    ifstream f("cmap.in");

    f>>n;

    for(i=0;i<n;++i)

    {

        I[i+1]=i+1;

        f>>x[i+1]>>y[i+1];

    }

    f.close();

    sort(I+1,I+1+n,compare);

    dm=D(x[I[1]],y[I[1]],x[I[2]],y[I[2]]);

    sol(1,n,dm);

    ofstream g("cmap.out");

    u=6;l=1;

    while(dm>l)

    {

        ++u;l=l*10;

    }

    g<<setprecision(u)<<dm;

    g.close();

    return 0;

}
