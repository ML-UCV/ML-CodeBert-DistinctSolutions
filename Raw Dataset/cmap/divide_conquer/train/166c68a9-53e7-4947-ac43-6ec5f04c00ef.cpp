#include <iostream>
#include <fstream>
#include <climits>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

const int nmax=100005;

struct punct

{

    long long x,y;

}v[nmax],l[nmax],aux[nmax];

bool comp(punct unu,punct doi)

{

    if(unu.x==doi.x) return unu.y<doi.y;

    return unu.x<doi.x;

}

long long abso(long long x)

{

    if(x<0) return -x;

    return x;

}

long long dist(punct unu,punct doi)

{

    return 1LL*(unu.x-doi.x)*(unu.x-doi.x)+(unu.y-doi.y)*(unu.y-doi.y);

}

int n,curr1,curr2,i,j,nr;

long double value;

long long divide(int st,int dr)

{

    if(st==dr) return LLONG_MAX;

    int m=(st+dr)/2;

    long long med=v[m].x;

    long long ret=1LL*min(divide(st,m),divide(m+1,dr));

    curr1=st;curr2=m+1;

    for(i=st;i<=dr;i++)

    {

        if((v[curr1].y<v[curr2].y||curr2>dr)&&curr1<=m) {aux[i]=v[curr1];curr1++;}

        else {aux[i]=v[curr2];curr2++;}

    }

    nr=0;

    for(i=st;i<=dr;i++)

    {

        v[i]=aux[i];

        if(abso(v[i].x-v[m].x)<=ret)

            l[++nr]=v[i];

    }

    for(i=1;i<=nr;i++)

    {

        for(j=i-1;j>=max(i-7,1)&&l[i].y-l[j].y<=ret;j--)

            ret=1LL*min(ret,dist(l[i],l[j]));

    }

    return ret;

}

int main()

{

    ifstream f("cmap.in");

    ofstream g("cmap.out");

    f>>n;

    for(i=1;i<=n;i++)

    {

        f>>v[i].x>>v[i].y;

    }

    sort(v+1,v+n+1,comp);

    value=divide(1,n);

    value=sqrt(value);

    g<<fixed<<setprecision(7)<<value;

    return 0;

}
