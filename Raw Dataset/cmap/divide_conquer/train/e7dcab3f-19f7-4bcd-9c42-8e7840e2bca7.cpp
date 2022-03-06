#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");

struct punct {long long int x,y;};punct v[100005],posibil[100005];

int n;

bool cmp1(punct a,punct b)

{

    return a.x<b.x;

}

bool cmp2(punct a ,punct b)

{

    return a.y>b.y;

}

long long det_dist(punct a,punct b)

{

    long long sol=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);

    return sol;

}

long long solve(int st,int dr)

{

    if(dr-st<=3)

    {

        long long minim=100000000000000;

        for(int i=st;i<dr;i++)

        {

            for(int j=i+1;j<=dr;j++)

            {

                long long p=det_dist(v[i],v[j]);

                if(p<minim) minim=p;

            }

        }

        return minim;

    }

    int mij=(st+dr)/2;

    long long stanga=solve(st,mij);

    long long dreapta=solve(mij+1,dr);

    long long distanta=min(stanga,dreapta);

    int cnt=0;

    for(int i=st;i<=dr;i++)

    {

        if(abs(v[i].x-v[mij].x)<=distanta)

        {

            posibil[++cnt]=v[i];

        }

    }

    sort(posibil+1,posibil+cnt+1,cmp2);

    long long dist_min=100000000000000;

    for(int i=1;i<=cnt;i++)

    {

        for(int j=i+1;j<=min(cnt,i+9);j++)

        {

            long long p=det_dist(posibil[i],posibil[j]);

            if(dist_min>p)

            {

                dist_min=p;

            }



        }

    }

    if(dist_min<distanta) return dist_min;

    return distanta;



}

int main()

{



f>>n;

for(int i=1;i<=n;i++) f>>v[i].x>>v[i].y;

sort(v+1,v+n+1,cmp1);

long long rez=solve(1,n);

double rad=sqrt(rez);

g<<setprecision(6)<<fixed<<rad;
}
