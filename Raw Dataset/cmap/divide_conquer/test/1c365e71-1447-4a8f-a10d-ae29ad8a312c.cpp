#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<utility>
#include<bits/stdc++.h>
using namespace std;

struct pct

{

    long int x,y;

};

int cmp1(const void *a,const void *b)

{

    pct x=*(pct*)a,y=*(pct*)b;

    if(x.x!=y.x)

        return x.x-y.x;

    return x.y-y.y;

}

int cmp2(const void *a,const void *b)

{

    pct x=*(pct*)a,y=*(pct*)b;

    if(x.y!=y.y)

        return x.y-y.y;

    return x.x-y.x;

}

double dist(pct a,pct b)

{

    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

}

double minim(double a,double b)

{

    if(a<b)

        return a;

    return b;

}

double deti(vector<pct> &v)

{

    double mini;

    if(v.size()<=3)

    {

        mini=dist(v[0],v[1]);

        if(v.size()==3)

        {

            mini=minim(mini,dist(v[0],v[1]));

            mini=minim(mini,dist(v[1],v[2]));

        }

        return mini;

    }

    vector<pct> vst,vdr;

    vector<pct> vmd;

    long int i,j;

    for(i=0;i<v.size()/2;i++)

        vst.push_back(v[i]);

    for(i=v.size()/2;i<v.size();i++)

        vdr.push_back(v[i]);

    long int mid=(vst[vst.size()-1].x+vdr[0].x)/2;

    mini=minim(deti(vst),deti(vdr));

    for(i=vst.size()-1;i>=0 && mid-vst[i].x<=mini;i--)

    {

        pct aux;

        aux=vst[i];

        vmd.push_back(aux);

    }

    for(i=0;i<vdr.size() && vdr[i].x-mid<=mini;i++)

    {

        pct aux;

        aux=vdr[i];

        vmd.push_back(aux);

    }

    qsort(vmd.data(),vmd.size(),sizeof(pct),cmp2);

    for(i=0;i<(long int)vmd.size()-1;i++)

        for(j=i+1;j<vmd.size() && vmd[j].y-vmd[i].y<=mini;j++)

            mini=minim(mini,dist(vmd[i],vmd[j]));

    return mini;

}

int main()

{

    ifstream f("cmap.in");

    ofstream g("cmap.out");

    long int i,n;

    vector<pct> v;

    f>>n;

    for(i=0;i<n;i++)

    {

        pct aux;

        f>>aux.x>>aux.y;

        v.push_back(aux);

    }

    qsort(v.data(),n,sizeof(pct),cmp1);

    g<<fixed<<setprecision(6)<<deti(v);

    return 0;

}
