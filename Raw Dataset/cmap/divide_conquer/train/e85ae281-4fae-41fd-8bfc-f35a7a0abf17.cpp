#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

ifstream in("cmap.in");

ofstream out("cmap.out");



struct punct

{

    int x;

    int y;

};

punct v[100001],a[100001];

int n;

bool comparax(const punct &A,const punct &B)

{

    return A.x<B.x;



}bool comparay(const punct &A,const punct &B)

{

    return A.y<B.y;



}

inline long long ridicP(long long x )

{

        return x*x;

}

long long distanta_nosqrt( const punct &A,const punct &B)

{

    return ridicP(A.x-B.x)+ridicP(A.y-B.y);

}

long long distantaminima(int st,int dr)

{

        long long minn=0x7FFFFFFFFFFFFFFFLL;



    for(int i=st;i<dr;i++)

    {

        for(int j=i+1;j<=dr;j++)

            {

                long long aux=distanta_nosqrt(v[i],v[j]);

                if(aux<minn)

                    minn=aux;

            }

    }

    return minn;

}

long long distanta(int st,int dr)

{

        if(dr-st<3)return distantaminima(st,dr);

        int mij=(st+dr)/2;

        long long d1,d2,dg;

        d1=distanta(st,mij);

        d2=distanta(mij,dr);

        dg=min(d1,d2);

        int cnt=0;

        for(int i=st;i<=dr;i++)

        {

            if(ridicP(v[i].x-v[mij].x)<dg)

                a[++cnt]=v[i];



        }

        sort(a+1,a+cnt+1,comparay);

        for(int i=1;i<cnt;i++)

        {

            for(int j=i+1;j<=cnt&&ridicP(a[j].y-a[i].y)<dg;j++)

            {

                    d1=distanta_nosqrt(a[i],a[j]);

                if(dg>d1)dg=d1;

            }

        }

        return dg;



}



int main()

{

    in>>n;

    for(int i=1;i<=n;i++)

        in>>v[i].x>>v[i].y;

    sort(v+1,v+n+1,comparax);

    out<<fixed<<setprecision(6)<<sqrt(distanta(1,n));

    return 0;

}
