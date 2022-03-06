#include<bits/stdc++.h>
using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");

int n,m,t[200001],d[200001],ct;

bool bag[400001];

vector<int>v[200001];

pair<int,pair<int,int>>mu[400001];

int rep(int x)

{

    if(t[x]==0)

        return x;

    t[x]=rep(t[x]);

    return t[x];

}

int main()

{

    fin>>n>>m;

    for(int i=1;i<=m;i++)

    {

        fin>>mu[i].second.first>>mu[i].second.second>>mu[i].first;

        v[mu[i].second.first].push_back(mu[i].second.second);

        v[mu[i].second.second].push_back(mu[i].second.first);

    }

    sort(mu+1,mu+m+1);

    for(int i=1;i<=m;i++)

    {

        int x=rep(mu[i].second.second);

        int y=rep(mu[i].second.first);

        if(x!=y)

        {

            if(d[x]>d[y])

            {

                t[y]=x;

                d[y]++;

            }

            else if(d[x]<d[y])

            {

                t[x]=y;

                d[x]++;

            }

            else

            {

                d[x]++;

                d[y]++;

                t[x]=y;

            }

            ct+=mu[i].first;

            bag[i]=true;

        }

    }

    fout<<ct<<"\n"<<n-1<<"\n";

    for(int i=1;i<=m;i++)

        if(bag[i])

            fout<<mu[i].second.first<<" "<<mu[i].second.second<<"\n";

}
