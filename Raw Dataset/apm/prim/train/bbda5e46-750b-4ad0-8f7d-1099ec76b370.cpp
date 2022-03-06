#include <bits/stdc++.h>
#include <queue>
#include <vector>


using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");



int n,m,viz[200005],cost;

vector<pair<int,int> >graph[200005];

vector<pair<int,int> >sol;

struct edge

{

    int x;

    int y;

    int c;



    bool operator<(const edge &other) const {

        if(c!=other.c)

            return c>other.c;

        return y>other.y;

    }

};

priority_queue<edge,vector<edge> >q;



void read()

{

    fin>>n>>m;

    int x,y,c;

    for(int i=0; i<m; i++)

    {

        fin>>x>>y>>c;

        graph[x].push_back(make_pair(y,c));

        graph[y].push_back(make_pair(x,c));

    }

}



void prim()

{

    viz[1]=1;

    int nr=graph[1].size();

    for(int i=0; i<nr; i++)

    {

        edge neww;

        neww.x=1;

        neww.y=graph[1][i].first;

        neww.c=graph[1][i].second;

        q.push(neww);

    }

    for(int k=0; k<n-1; k++)

    {

        int node=0;

        while(!node&&!q.empty())

        {

            edge neww=q.top();

            if(!viz[neww.x])

            {

                sol.push_back(make_pair(neww.x,neww.y));

                viz[neww.x]=1;

                node=neww.x;

                cost+=neww.c;

            }

            if(!viz[neww.y])

            {

                sol.push_back(make_pair(neww.x,neww.y));

                viz[neww.y]=1;

                node=neww.y;

                cost+=neww.c;

            }

            q.pop();

        }

        nr=graph[node].size();

        for(int i=0; i<nr; i++)

        {

            edge neww;

            neww.x=node;

            neww.y=graph[node][i].first;

            neww.c=graph[node][i].second;

            q.push(neww);

        }

    }

}



void afish()

{

    fout<<cost<<"\n"<<n-1<<"\n";

    for(int i=0; i<n-1; i++)

        fout<<sol[i].first<<" "<<sol[i].second<<"\n";

}



int main()

{

    read();

    prim();

    afish();

    return 0;

}
