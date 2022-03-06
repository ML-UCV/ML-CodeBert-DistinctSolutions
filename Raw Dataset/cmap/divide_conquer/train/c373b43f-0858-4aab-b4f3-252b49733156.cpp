#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>


using namespace std;



ifstream f("cmap.in");

ofstream g("cmap.out");







struct punct

{

    int x,y;

}v[100000],v2[100000];



int n;



bool sortare_x (punct a,punct b)

{

    return a.x<b.x;

}



bool sortare_y(punct a,punct b)

{

    return a.y<b.y;

}



long long distanta(punct a,punct b)

{

    long long ecx=1LL*(a.x-b.x);

    long long ecy=1LL*(a.y-b.y);

    return ecx*ecx+ecy*ecy;

}





long long div_imp(int st,int dr)

{

    int mij;

    long long dist1,dist2,dmin,delta;

    if(dr-st==1)

        return distanta(v[st],v[dr]);

    if (dr-st==2)

        return min(distanta(v[st],v[st+1]),min(distanta(v[st+1],v[dr]),distanta(v[st],v[dr])));

    mij=(st+dr)/2;

    dist1=div_imp(st,mij) ;

    dist2=div_imp(mij+1,dr) ;

    dmin=min(dist1,dist2);

    delta=ceil(sqrt(dmin));

    int i,j,k=0;

    for(i=st;i<=dr;i++)

        if(abs(v[i].x-v[mij].x)<=delta)

        {

            v2[k].x=v[i].x;

            v2[k].y=v[i].y;

            k++;

        }

    sort(v2,v2+k,sortare_y);

    for(i=0;i<k;i++)

        for(j=i+1;j<=(i+7)&&j<k;j++)

            dmin=min(dmin,distanta(v2[i],v2[j]));

    return dmin;

}



int main()

{

    int n,i;

    f>>n;

    for(i=0;i<n;i++)

        f>>v[i].x>>v[i].y;

    sort(v,v+n,sortare_x);

    g <<fixed<<setprecision(6)<<sqrt(div_imp(0,n-1));

    return 0;

}
