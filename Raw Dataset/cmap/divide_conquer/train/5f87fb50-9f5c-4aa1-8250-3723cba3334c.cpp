#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>


using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");







struct punct

{

    int x,y;

};



punct v[100100];

punct curr[100100];

int n,i;



double dist(const punct &a,const punct &b)

{

    return (double)sqrt( 1LL * (a.x-b.x) * (a.x-b.x) + 1LL * (a.y-b.y) * (a.y-b.y) );

}



bool cmp0(const punct &a,const punct &b)

{

    if(a.y==b.y)

        return a.x<b.x;

    return a.y<b.y;

}



bool cmpcurr(const punct &a,const punct &b)

{

    if(a.x==b.x)

        return a.y<b.y;

    return a.x<b.x;

}



double compute(int s,int d)

{

    if(d-s<3)

    {

        double mn = 1e9+1;

        int i,j;

        for(i=s; i<d; ++i)

            for(j=i+1; j<=d; ++j)

                mn = min(mn,dist(v[i],v[j]));

        return mn;

    }

    double mn = min(compute(s,(s+d)/2),compute((s+d)/2+1,d));

    int k = 0, i, j, ls, ld;

    double mij = (v[(s+d)/2].y + v[(s+d)/2+1].y)/2;

    i=(s+d)/2;

    while(i>=s && mij-v[i].y<=mn)

        curr[k++]=v[i--];

    i=(s+d)/2+1;

    while(i<=d && v[i].y-mij<=mn)

        curr[k++]=v[i++];

    sort(curr,curr+k,cmpcurr);

    for(i=0; i<k; ++i)

        for(j=i+1; j<i+8 && j<k; ++j)

            mn=min(mn,dist(curr[i],curr[j]));

    return mn;

}



int main()

{

    fin>>n;

    for(i=1; i<=n; ++i)

        fin>>v[i].x>>v[i].y;

    sort(v+1,v+n+1,cmp0);

    fout<<setprecision(6)<<fixed<<compute(1,n);

}
