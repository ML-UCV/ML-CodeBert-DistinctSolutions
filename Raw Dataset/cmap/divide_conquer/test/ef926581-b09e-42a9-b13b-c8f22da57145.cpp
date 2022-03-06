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

const long long INF=9e18;

const int MAXI=100005;

vector<pair<long long,long long> > temp(MAXI);



long long dist(const pair<long long,long long> &p1,const pair<long long,long long> &p2)

{

    return (long long)(p1.first-p2.first)*(p1.first-p2.first)+(long long)(p1.second-p2.second)*(p1.second-p2.second);

}

bool Sort(const pair<long long,long long> &p1,const pair<long long,long long> &p2)

{

    return p1.first<p2.first;

}

long long minDistance(vector<pair<long long,long long> > &v,vector<pair<long long,long long> > &y,int l,int r)

{ if(l>=r-1)

        return INF;

   if(r-l==2)

   {

       if(y[l].first>y[l+1].first)

        swap(y[l],y[l+1]);

        return dist( v[l],v[l+1]);

   }

   int m=(l+r)/2;

   long long d,d1,d2,dis;

   int i,j;

   d1=minDistance(v,y,m,r);

   d2=minDistance(v,y,l,m);

   d=min(d1,d2);

   dis=(int) ceil(sqrt(d));



    merge(y.begin() + l, y.begin() + m, y.begin() +m, y.begin() + r, temp.begin());

    copy(temp.begin(), temp.begin() + (r - l), y.begin() + l);

    int temp_size=0;

   for(i=l;i<=r;i++)

        if(abs(y[i].second-v[m].first)<=dis)

           temp[temp_size++]=y[i];



    for(i=0;i<temp_size-1;i++)

        for(j=i+1;j<=i+7 && j<temp_size;j++)

            d=min(d,dist(temp[i],temp[j]));

 return d;

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

    sort(v.begin(),v.end(),Sort);

    for(i=0;i<n;i++)

        z.push_back(make_pair(v[i].second,v[i].first));

    g<<fixed<<setprecision(6)<<sqrt(minDistance(v,z,0,n-1))<<"\n";

    return 0;

}
