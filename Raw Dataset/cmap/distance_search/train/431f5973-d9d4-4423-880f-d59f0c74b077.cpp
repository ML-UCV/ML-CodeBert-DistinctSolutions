#include <algorithm>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
using namespace std;

FILE*f=freopen("cmap.in","r",stdin);

ofstream g("cmap.out");

char buff[200000];

int pos=0,n,i,j;

long long dmin,dd;

struct gigi

{

    int x,y;

} v[100002];

bool fct (gigi a,gigi b)

{

  if(a.x==b.x) return(a.y<b.y);

  else

        return(a.x<b.x);

}

inline long long dist(gigi a,gigi b)

{

    return ((long long)((long long)(a.x-b.x)*(a.x-b.x)+(long long)(a.y-b.y)*(a.y-b.y)));

}

inline void read(int &nr)

{ int semn=1;

    while(buff[pos] < '0' || buff[pos] > '9') if(++pos == 200000) fread(buff, 1,200000, stdin), pos = 0;

    nr = 0;

    if(buff[pos-1]=='-') semn=-1;

    while('0' <= buff[pos] && buff[pos] <= '9')

    {

        nr = (nr<<1)+(nr<<3)+ buff[pos] - '0';

        if(++pos == 200000) fread(buff, 1,200000, stdin), pos = 0;

    }

    nr*=semn;

}

int main()

{

    read(n);

    for(i=1; i<=n; i++)

    {

        read(v[i].x);

        read(v[i].y);

    }

    sort(v+1,v+n+1,fct);

    dmin=(1LL<<62);

    for(i=n-1; i>=1; i--)

        for(j=i+1; j<=i+3 && j<=n; j++)

        {

            dd=dist(v[i],v[j]);

            if(dmin>dd) dmin=dd;

        }

    g<<setprecision(6)<<fixed;

    g<<sqrt(dmin);

}
