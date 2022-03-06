#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");



const long long inf=9e18;



const int Max_N=100005;



vector<pair<long long,long long>> temp(Max_N);



long long distanta(const pair<long long,long long> &p1,const pair<long long,long long> &p2)

{

    return (long long)(p1.first-p2.first)*(p1.first-p2.first)+(long long)(p1.second-p2.second)*(p1.second-p2.second);

}



bool ComparX(const pair<long long,long long> &p1,const pair<long long,long long> &p2)

{

    return p1.first<p2.first;

}



long long distantaMinima(vector<pair<long long,long long>> &v,vector<pair<long long,long long>> &y,int stg,int dr)

{

   if(stg>=dr-1)

        return inf;

   if(dr-stg==2)

   {

       if(y[stg].first>y[stg+1].first)

        swap(y[stg],y[stg+1]);

        return distanta( v[stg],v[stg+1]);

   }

   int mijloc=(stg+dr)/2;

   long long dist,d1,d2,delta;

   int i,j;

   d1=distantaMinima(v,y,mijloc,dr);

   d2=distantaMinima(v,y,stg,mijloc);

   dist=min(d1,d2);

   delta=(int) ceil(sqrt(dist));

   merge(y.begin()+stg, y.begin()+mijloc, y.begin()+mijloc, y.begin()+dr, temp.begin());

   copy(temp.begin(), temp.begin() + (dr - stg), y.begin() + stg);

   int temp_size=0;

   for(i=stg;i<=dr;i++)

        if(abs(y[i].second-v[mijloc].first)<=delta)

           temp[temp_size++]=y[i];

    for(i=0;i<temp_size-1;i++)

        for(j=i+1;j<=i+7 && j<temp_size;j++)

            dist=min(dist,distanta(temp[i],temp[j]));

 return dist;

}

int main()

{ int n,i;

    long long x,y;

    vector<pair<long long,long long> > v,z;

    f>>n;

    for(i=0;i<n;i++)

    {

        f>>x>>y;

        v.push_back(make_pair(x,y));

    }

    sort(v.begin(),v.end(),ComparX);



    for(i=0;i<n;i++)

        z.push_back(make_pair(v[i].second,v[i].first));



    g<<fixed<<setprecision(6)<<sqrt(distantaMinima(v,z,0,n-1))<<"\n";

    f.close();

    g.close();

    return 0;

}
