#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <fstream>


using namespace std;

ifstream fin("cmap.in");

ofstream fout("cmap.out");

pair<int ,int> w[100010],aux[100010],v[100010];

int n,i;

long long global=(1LL<<60);

long long dist(pair<int,int> a, pair<int,int> b)

{

    return 1LL*(a.first-b.first)*(a.first-b.first)+

           1LL*(a.second-b.second)*(a.second-b.second);

}

void msort(int st,int m,int dr)

{

    int i=st,j=m+1,k=st-1;

    for(; i<=m&&j<=dr;)

    {

        if(v[i].second<v[j].second){

            w[++k]=v[i++];

        }

        else

            w[++k]=v[j++];

    }

    while(i<=m){

        w[++k]=v[i++];

    }

    while(j<=dr){

        w[++k]=v[j++];

    }

    for(i=st;i<=dr;i++)

        v[i]=w[i];

}

long long rec(int st,int dr)

{

    long long r;

    if(dr-st==1)

    {

        r=dist(v[st],v[dr]);

        msort(st,st,dr);

        return r;

    }

    if(dr-st==2)

    {

        r=min( min(dist(v[st],v[st+1]), dist(v[st+1],v[dr])), dist(v[st],v[dr]));

        msort(st,st,st+1);

        msort(st,st+1,dr);

        return r;

    }

    int m=(st+dr)/2;

    long long stsol=rec(st,m);

    long long drsol=rec(m+1,dr);

    r=min(stsol,drsol);

    global=min(r,global);

    msort(st,m,dr);

    int k=0;

    for(int i=st; i<=dr; i++)

    {

        if(abs(v[i].first-v[m].first)<=global)

        {

            aux[++k]=v[i];

        }

    }

    for(int i=1; i<k; i++)

    {

        for(int j=i+1; j<=k&&j<=i+7; j++)

        {

            r=min(r,dist(aux[i],aux[j]));

        }

    }

    return r;

}

int main()

{

    fin>>n;

    for(i=1; i<=n; i++)

    {

        fin>>v[i].first>>v[i].second;

    }

    sort(v+1,v+n+1);

    fout<<setprecision(6)<<fixed<<(double)sqrt(rec(1,n));

}
