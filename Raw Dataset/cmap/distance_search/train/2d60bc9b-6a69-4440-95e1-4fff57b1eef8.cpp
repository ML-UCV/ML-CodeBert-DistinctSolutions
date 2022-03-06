#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>


using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



typedef long double ll;



const int N=100000+5;



struct point

{

    int x;

    int y;

    ll di;

};



ll p(int x)

{

    return x*(long long)x;

}



ll d(point a,point b)

{

    int dx=a.x-b.x;

    int dy=a.y-b.y;

    return p(dx)+p(dy);

}



int n,x=(1<<30),y=(1<<30);

point v[N];



bool cmp(point a,point b)

{

    return a.di<b.di;

}



int main()

{

    fin>>n;

    for(int i=1;i<=n;i++)

    {

        fin>>v[i].x>>v[i].y;

        if(v[i].x<x) x=v[i].x;

        if(v[i].y<y) y=v[i].y;

    }

    for(int i=1;i<=n;i++)

    {

        v[i].di=d(v[i],{x,y});

    }

    sort(v+1,v+n+1,cmp);

    int val=(int)1e7/n;

    ll ans=(1LL<<60);

    for(int i=1;i<=n;i++)

    {

        int dr=min(n,i+val);

        for(int j=i+1;j<=dr;j++)

        {

            ans=min(ans,d(v[i],v[j]));

        }

    }

    long double x=ans;

    x=sqrt(x);

    fout<<fixed<<setprecision(6)<<x<<"\n";

    return 0;

}
