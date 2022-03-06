#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;



int n;



struct punct

{

    long long x,y;

} vPuncte[100002];



bool cmpX(punct p1,punct p2)

{

    return p1.x<p2.x;

}



double dist(punct p1,punct p2)

{

    double rez;

    rez=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));

    return rez;

}



void citire()

{

    scanf("%d",&n);

    for(int i=1; i<=n; i++)

    {

        scanf("%lld%lld",&vPuncte[i].x,&vPuncte[i].y);

    }

}



double solve()

{

    sort(vPuncte+1,vPuncte+n+1,cmpX);

    double rez;

    rez=dist(vPuncte[1],vPuncte[2]);

    for(int i=2; i<n; i++)

        for(int j=i+1; j<=n&&vPuncte[j].x-vPuncte[i].x<rez; j++)

        {

            rez=min(rez,dist(vPuncte[i],vPuncte[j]));

        }

    return rez;

}

int main()

{

    freopen("cmap.in","r",stdin);

    freopen("cmap.out","w",stdout);

    citire();

    printf("%lf",solve());

    return 0;

}
