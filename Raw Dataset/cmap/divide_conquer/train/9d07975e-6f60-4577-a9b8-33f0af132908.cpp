#include <limits.h>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <cstdio>


using namespace std;

struct tip

{

    int x, y;

} pct[100005],sec[100005],aux[100005],yy[100005];

int n;



long long rasp=LLONG_MAX;



long long minim(long long a, long long b)

{

    if(a<b)return a;

    return b;

}



long long dist(tip a,tip b)

{

    long long x=(a.x-b.x), y=(a.y-b.y);

    return x*x+y*y;

}





void interc(int st, int m, int dr)

{

    int i=st, j=m+1,k=st;

    while(i<=m && j<=dr)

        if(pct[i].x<=pct[j].x)

            sec[k++]=pct[i++];

        else

            sec[k++]=pct[j++];

    while(j<=dr)sec[k++]=pct[j++];

    while(i<=m)sec[k++]=pct[i++];

    for(k=st; k<=dr; ++k)pct[k]=sec[k];



}



void intercy(int st, int m, int dr)

{

    int i=st, j=m+1,k=st;

    while(i<=m&&j<=dr)

        if(sec[i].y<=sec[j].y)

                aux[k++]=sec[i++];

        else

                aux[k++]=sec[j++];

    while(j<=dr)aux[k++]=sec[j++];

    while(i<=m)aux[k++]=sec[i++];

    for(k=st; k<=dr; ++k)sec[k]=aux[k];

}



void srt(int st, int dr)

{

    int m=(st+dr)/2;

    if(st<dr)

    {

        srt(st,m);

        srt(m+1,dr);

        interc(st,m,dr);

    }

}



void genesa(int st, int dr)

{



    int m=(st+dr)/2,l=pct[m].x;

    if(dr-st<3)

    {

        for(int i=st; i<dr; ++i)

            for(int j=i+1; j<=dr; ++j)

            {

                long long tz=dist(pct[i],pct[j]);

                rasp=minim(rasp,tz);

                if(sec[i].y>sec[j].y)swap(sec[i],sec[j]);

            }

        return;

    }

    genesa (st, m);

    genesa (m+1,dr);

    intercy(st,m,dr);

    int k=0;

    for(int i=st; i<=dr; ++i)

        if((long long)(l-sec[i].x)*(l-sec[i].x)<=rasp)yy[++k]=sec[i];

    for(int i=1; i<k; i++)

        for(int j=i+1; j<=k&&j<=i+8; j++)

        {

            long long tz=dist(yy[i],yy[j]);

            rasp=minim(rasp,tz);

        }

}



int main()

{

    FILE *in=fopen("cmap.in","r"),*out=fopen("cmap.out","w");

    fscanf (in, "%d",&n);

    for(int i=0; i<n; ++i)

        fscanf(in,"%d%d",&pct[i].x,&pct[i].y);

    srt(0,n-1);

    for(int i=0; i<n; i++)

                    sec[i]=pct[i];

    genesa(0,n-1);

    fprintf(out, "%.7f",sqrt(rasp));

    return 0;

}
