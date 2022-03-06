#include <iostream>
#include <fstream>
#include <queue>
#include <vector>




using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");

vector <pair <int,int > > v[200010];

priority_queue <pair<int, pair<int,int> >, vector <pair<int, pair <int,int > > >, greater <pair<int, pair <int,int > > > >q;

int n,m,i,x,y,c,viz[200010],t[200010],sum;

pair<int, pair<int,int> > aux;

void prim(int st)

{

    viz[st]=1;

    int nrm=0,ok=0;

    while(nrm<n-1)

    {

        if(ok==0)

        {

            for(int i=0;i<v[st].size();i++)

            {

               if(viz[v[st][i].second]==0)

               {

                   q.push(make_pair( v[st][i].first,make_pair(v[st][i].second,st)));

               }

            }

        }

        if(viz[q.top().second.first]==0)

        {

            nrm++;

            t[q.top().second.first]=q.top().second.second;

            viz[q.top().second.first]=1;

            sum=sum+q.top().first;

            ok=0;

        }

        else

        {

            ok=1;

        }

        st=q.top().second.first;

        q.pop();

    }

}

int main()

{

    fin>>n>>m;

    for(i=1;i<=m;i++)

    {

        fin>>x>>y>>c;

        v[x].push_back(make_pair(c,y));

        v[y].push_back(make_pair(c,x));

    }

    prim(1);

    fout<<sum<<'\n'<<n-1<<'\n';

    for(int i=2;i<=n;i++)

    {

        fout<<i<<" "<<t[i]<<'\n';

    }

    return 0;

}
