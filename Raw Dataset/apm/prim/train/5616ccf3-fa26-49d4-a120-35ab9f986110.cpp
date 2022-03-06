#include <bits/stdc++.h>
using namespace std;

ifstream fin("apm.in");ofstream fout("apm.out");

vector<pair<int,pair<int,int> > >a[200005];

vector<pair<int,pair<int,int> > >::iterator it;

pair<int,pair<int,int> >var;

pair<int,pair<int,int> >var2;

vector<pair<int,int> >sol;

vector<pair<int,int> >::iterator it2;

pair<int,int>varsol;

priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >q;

int n,m,x,y,co,nrviz,cst,viz[200005],t[200005],nrm;

void citire()

{

    fin>>n>>m;

    while(fin>>x>>y>>co)

    {

        var.first=co;

        var.second.first=y;

        var.second.second=x;

        a[x].push_back(var);

        var.first=co;

        var.second.first=x;

        var.second.second=y;

        a[y].push_back(var);

    }

}

int main()

{

    citire();

    for(it=a[1].begin();it<a[1].end();it++)

    {

        var.first=it->first;

        var.second.first=it->second.first;

        var.second.second=it->second.second;

        q.push(var);

    }

    viz[1]=1;t[1]=0;nrviz+=1;

    while(nrviz<n)

    {

        var=q.top();

        q.pop();

        if(viz[var.second.first]==0)

        {

            cst+=var.first;nrm+=1;

            varsol.first=var.second.second;

            varsol.second=var.second.first;

            sol.push_back(varsol);

            t[var.second.first]=var.second.second;

            int where=var.second.first;

            viz[var.second.first]=1;

            nrviz+=1;

            for(it=a[where].begin();it<a[where].end();it++)

            {

                var2.first=it->first;

                var2.second.first=it->second.first;

                var2.second.second=it->second.second;

                q.push(var2);

            }

        }

    }

    fout<<cst<<'\n'<<nrm<<'\n';

    for(it2=sol.begin();it2<sol.end();it2++)

    {

        fout<<it2->first<<" "<<it2->second<<'\n';

    }

    fin.close();fout.close();return 0;

}
