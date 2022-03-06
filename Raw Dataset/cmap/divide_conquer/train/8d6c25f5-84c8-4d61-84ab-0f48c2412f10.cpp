#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;

ifstream fin("cmap.in");

ofstream fout("cmap.out");

const long long inf=9e18;

vector<pair<long long,long long> > t(100000);



long long dist(const pair<long long,long long> &i,const pair<long long,long long> &j)

{

    return (long long )(i.first-j.first)*(i.first-j.first)+(long long)(i.second-j.second)*(i.second-j.second);

}

bool CmpX(const pair<long long,long long> &i,const pair<long long,long long> &j)

{ return i.first<j.first;

}



long long minDistance(vector<pair<long long,long long> > &v,vector<pair<long long,long long> > &z,int st,int dr)

{ if(st>=dr-1)

        return inf;

   if(dr-st==2)

   {

       if(z[st].first>z[st+1].first)

        swap(z[st],z[st+1]);

        return dist( v[st],v[st+1]);

   }

   int m=(st+dr)/2;

   long long d,d1,d2,delta;

   int i,j;

   d1=minDistance(v,z,m,dr);

   d2=minDistance(v,z,st,m);

   d=min(d1,d2);





    merge(z.begin() + st, z.begin() + m, z.begin() + m, z.begin() + dr, t.begin());

    copy(t.begin(), t.begin() + (dr - st), z.begin() + st);

    int sizet=0;

   for(i=st;i<=dr;i++)

        if(abs(z[i].second-v[m].first)<=d)

           t[sizet++]=z[i];



    for(i=0;i<sizet-1;i++)

        for(j=i+1;j<=i+7 && j<sizet;j++)

            d=min(d,dist(t[i],t[j]));

 return d;

}

int main()

{ int n,i;

    long long x,y;

    vector<pair<long long,long long> > v,z;

    fin>>n;

    for(i=0;i<n;i++)

    {

        fin>>x>>y;

        v.push_back(make_pair(x,y));

    }

    sort(v.begin(),v.end(),CmpX);



    for(i=0;i<n;i++)

        z.push_back(make_pair(v[i].second,v[i].first));



    fout<<fixed<<setprecision(6)<<sqrt(minDistance(v,z,0,n-1))<<"\n";

    fin.close();

    fout.close();

    return 0;

}
