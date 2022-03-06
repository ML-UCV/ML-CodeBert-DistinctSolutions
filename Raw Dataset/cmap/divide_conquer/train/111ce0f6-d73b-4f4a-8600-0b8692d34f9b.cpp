#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <algorithm>


using namespace std;







struct punct

{

    double x;

    double y;

};



typedef double ull;



punct v[110000],z[110000],w[110000];



bool cmp(punct a,punct b)

{

    return a.x<b.x;

}



double distanta(punct a,punct b)

{

    return (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);

}



double dei (int l, int r)

{

    if(r-l+1==3)

    {

        if(v[l].y>v[l+1].y)

            swap(v[l],v[l+1]);

        if(v[l+1].y>v[l+2].y)

            swap(v[l+1],v[l+2]);

        if(v[l].y>v[l+1].y)

            swap(v[l],v[l+1]);

        return min(distanta(v[l],v[l+1]),min(distanta(v[l+1],v[l+2]),distanta(v[l],v[l+2])));

    }

    if(r-l+1==2)

    {

        if(v[l].y>v[l+1].y)

            swap(v[l],v[l+1]);

        return distanta(v[l],v[l+1]);

    }

    else

    {

        int m=(l+r)/2;

        double mediana=v[m].x;

        ull delta=min(dei(l,m),dei(m+1,r));

        int r2=0;

        int rdelta=sqrt(delta);

        int i,j,k;

        i=k=l;

        j=m+1;

        while(i<=m&&j<=r)

            if(v[i].y<v[j].y)

                z[k++]=v[i++];

            else

                z[k++]=v[j++];

        while(i<=m)

            z[k++]=v[i++];

        while(j<=r)

            z[k++]=v[j++];

        for(i=l;i<=r;i++)

        {

            v[i]=z[i];

            if(v[i].x-mediana<=rdelta&&v[i].x-mediana>=-rdelta)

                w[++r2]=v[i];

        }

        for(i=1;i<=r2;i++)

        {

            j=min(r2,i+7);

            for(k=i+1;k<=j;k++)

                delta=min(delta,distanta(w[i],w[k]));

        }

        return delta;

    }

}





int main()

{

    ifstream f("cmap.in");

    ofstream o("cmap.out");

    int n,i;

    f>>n;

    for(i=1;i<=n;i++)

        f>>v[i].x>>v[i].y;

    sort(v+1,v+n+1,cmp);

    o<<setprecision(6)<<fixed<<sqrt(dei(1,n));

    f.close();

    o.close();

}
