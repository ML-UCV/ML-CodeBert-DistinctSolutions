#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

ifstream fin("cmap.in");

ofstream fout("cmap.out");

long long dist(pair<int,int> p1, pair<int,int> p2)

{

    return (long long)(p1.first-p2.first)*(p1.first-p2.first)+(long long)(p1.second-p2.second)*(p1.second-p2.second);

}

bool CmpX(pair<int,int>p1,pair<int,int>p2)

{ return p1.first<p2.first;

}

bool CmpY(pair<int,int>p1,pair<int,int>p2)

{ return p1.second<p2.second;

}

long long minDistance(vector<pair<int,int> > &v,int st,int dr)

{ if(dr-st==1)

        return dist(v[st],v[dr]);

   if(dr-st==2)

   {

       long long d1,d2,d3;

       d1=dist(v[st],v[dr]);

       d2=dist(v[st+1],v[dr]);

       d3=dist(v[st],v[st+1]);

       return min(d1,min(d2,d3));

   }

   int m=(st+dr)/2;

   long long d,d1,d2,delta;

   int i,j;

   d1=minDistance(v,m+1,dr);

   d2=minDistance(v,st,m);

   d=min(d1,d2);

    delta=(int) ceil(sqrt(d));

   vector<pair<int,int> > temp;

   for(i=st;i<=dr;i++)

        if(abs(v[i].first-v[m].first)<=delta)

           temp.push_back(v[i]);

    sort(temp.begin(),temp.end(),CmpY);

    for(i=0;i<temp.size();i++)

        for(j=i+1;j<=i+7 && j<temp.size();j++)

            d=min(d,dist(temp[i],temp[j]));

 return d;

}

int main()

{ int n,i,x,y;

    vector<pair<int,int> > v;

    fin>>n;

    for(i=0;i<n;i++)

    {

        fin>>x>>y;

        v.push_back(make_pair(x,y));

    }

    sort(v.begin(),v.end(),CmpX);



    fout<<fixed<<setprecision(6)<<sqrt(minDistance(v,0,n-1));

    fin.close();

    fout.close();

    return 0;

}
