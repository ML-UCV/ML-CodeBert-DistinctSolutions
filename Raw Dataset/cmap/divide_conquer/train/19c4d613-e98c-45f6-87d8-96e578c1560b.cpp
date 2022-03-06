#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>


using namespace std;



ifstream f("cmap.in");

ofstream g("cmap.out");



struct punct

{

    int x,y;

};



long long distanta(punct p1, punct p2)

{

    return (long long) (p1.x-p2.x)*(p1.x-p2.x)+ (long long) (p1.y-p2.y)*(p1.y-p2.y);

}

bool comparX(punct p1,punct p2)

{

    return p1.x<p2.x;

}

bool comparY(punct p1,punct p2)

{

    return p1.y<p2.y;

}

long long DistantaMinima(vector<punct> &v,int stg,int dr)

{

   int mijloc=(stg+dr)/2;

   long long dist,distdr,diststg,delta;

   int i,j;

   vector<punct> temp;

   if(dr-stg==1)

   {

        return distanta(v[stg],v[dr]);

   }

   if(dr-stg==2)

   {

       long long dist1,dist2,dist3;

       dist1=distanta(v[stg],v[dr]);

       dist2=distanta(v[stg+1],v[dr]);

       dist3=distanta(v[stg],v[stg+1]);

       return min(dist1,min(dist2,dist3));

   }

   diststg=DistantaMinima(v,stg,mijloc);

   distdr=DistantaMinima(v,mijloc+1,dr);

   dist=min(diststg,distdr);

   delta=(int) ceil(sqrt(dist));

   for(i=stg;i<=dr;i++)

   {

        if(abs(v[i].x-v[mijloc].x)<=delta)

        {

           temp.push_back(v[i]);

        }

   }

    sort(temp.begin(),temp.end(),comparY);

    for(i=0; i<temp.size(); i++)

    {

        for(j=i+1; j<=i+7 && j<temp.size(); j++)

        {

            dist=min(dist,distanta(temp[i],temp[j]));

        }

    }

    return dist;

}

int main()

{

    int n,i,x,y;

    vector<punct> v;

    punct p;

    f>>n;

    for(i=0;i<n;i++)

    {

        f>>p.x>>p.y;

        v.push_back(p);

    }

    sort(v.begin(),v.end(),comparX);

    g<<fixed<<setprecision(6)<<sqrt(DistantaMinima(v,0,n-1));

    f.close();

    g.close();

    return 0;

}
