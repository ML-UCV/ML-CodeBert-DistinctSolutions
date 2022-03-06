#include <bits/stdc++.h>


using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");

int n;

struct punct

{

    int x,y;

};

punct a[100005];

bool cmpY(const punct &a, const punct &b)

{

    return a.y<b.y;

}

bool cmpX(const punct &a,const punct &b)

{

    return a.x<b.x;

}

long long dist(punct a,punct b)

{

    return 1LL*(b.x-a.x)*(b.x-a.x)+1LL*(b.y-a.y)*(b.y-a.y);

}

int modul(int x)

{

    if(x>=0)

        return x;

    else

        return -x;

}

long long cmap(int st,int dr)

{



    if(dr-st<=4)

    {



        long long sol=1LL<<60;

        for(int i=st;i<=dr;i++)

        {

            for(int j=i+1;j<=dr;j++)

            {

                sol=min(sol,dist(a[i],a[j]));

            }

        }

        return sol;

    }

    int mij=(st+dr)/2;

    long long minim=min(cmap(st,mij),cmap(mij+1,dr));

    int nr=0;

    punct b[100005];

    for(int i=st;i<=dr;i++)

    {

        if(modul(a[i].x-a[mij].x)<minim)

        {

            nr++;

            b[nr]=a[i];

        }

    }

    sort(b+1,b+nr+1,cmpY);

    for(int i=1;i<=nr;i++)

    {

        for(int j=i+1;j-i<8 && j<=nr;j++)

        {

            minim=min(minim,dist(b[i],b[j]));

        }

    }

    return minim;

}

int main()

{

    int i;

    f>>n;

    for(i=1;i<=n;i++)

    {

        f>>a[i].x>>a[i].y;

    }



    sort(a+1,a+n+1,cmpX);

    g<<fixed<<setprecision(6)<<sqrt(double(cmap(1,n)));

    return 0;

}
