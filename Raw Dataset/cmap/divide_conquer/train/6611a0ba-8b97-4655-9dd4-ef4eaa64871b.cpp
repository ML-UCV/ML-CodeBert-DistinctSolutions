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

const int Max_N=100005;

typedef long long ll;

vector<pair<ll,ll> > temp(Max_N);



long long dist(const pair<ll,ll> &p1,const pair<ll,ll> &p2)

{

    return (ll)(p1.first-p2.first)*(p1.first-p2.first)+(ll)(p1.second-p2.second)*(p1.second-p2.second);

}

bool CmpX(const pair<ll,ll> &p1,const pair<ll,ll> &p2)

{ return p1.first<p2.first;

}

bool CmpY(const pair<ll,ll>&p1,const pair<ll,ll>&p2)

{ return p1.second<p2.second;

}

long long minDistance(vector<pair<ll,ll> > &v,vector<pair<ll,ll> > &y,int st,int dr)

{ if(st>=dr-1)

        return inf;

   if(dr-st==2)

   {

       if(y[st].first>y[st+1].first)

        swap(y[st],y[st+1]);

        return dist( v[st],v[st+1]);

   }

   int m=(st+dr)/2;

   ll d,d1,d2,delta;

   int i,j;

   d1=minDistance(v,y,m,dr);

   d2=minDistance(v,y,st,m);

   d=min(d1,d2);

   delta=(int) ceil(sqrt(d));



    merge(y.begin() + st, y.begin() + m, y.begin() +m, y.begin() + dr, temp.begin());

    copy(temp.begin(), temp.begin() + (dr - st), y.begin() + st);

    int temp_size=0;

   for(i=st;i<=dr;i++)

        if(abs(y[i].second-v[m].first)<=delta)

           temp[temp_size++]=y[i];



    for(i=0;i<temp_size-1;i++)

        for(j=i+1;j<=i+7 && j<temp_size;j++)

            d=min(d,dist(temp[i],temp[j]));

 return d;

}

int main()

{ int n,i;

    ll x,y;

    vector<pair<ll,ll> > v,z;

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
