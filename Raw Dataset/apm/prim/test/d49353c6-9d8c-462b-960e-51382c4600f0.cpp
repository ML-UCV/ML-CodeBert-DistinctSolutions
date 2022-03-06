#include <fstream>
#include <vector>
#include <queue>
#include<cstdio>
using namespace std;



const int maxi=1<<30;



ifstream be("apm.in");

ofstream ki("apm.out");



void prim(vector<vector<pair<int,int> > >&adj ,int n)

{

    vector<bool>mstset(n+1,false);

    vector<int>parent(n+1,-1);

    vector<int>key(n+1,maxi);

    priority_queue<pair<int,int>,deque<pair<int,int> >,greater<pair<int,int> > >q;

    int src=1;

    int db=0;

    parent[src]=src;

    q.push({0,src});

    key[src]=0;

    while(!q.empty())

    {

        int u=q.top().second;

        int cost=q.top().first;

        q.pop();

        if(mstset[u] || cost!=key[u])continue;

        mstset[u]=true;

        db+=cost;

        for(auto p:adj[u])

        {

            int v=p.first;

            int c=p.second;

            if(mstset[v]==false && key[v]>c)

            {

                key[v]=c;

                q.push({key[v],v});

                parent[v]=u;

            }

        }

    }

    printf("%d\n%d\n",db,n-1);

    for (int i = 1; i <= n; i++)

    {

        if(i!=src)

        {

            printf("%d %d\n",i,parent[i]);

        }

    }



}





int main()

{

    freopen("apm.in","r",stdin);

 freopen("apm.out","w",stdout);

    int n,m;

    scanf("%d %d",&n,&m);

    vector<vector<pair<int,int> > >adj(n+1);

    for(int i=0;i<m;i++)

    {

        int x,y,c;

        scanf("%d %d %d",&x,&y,&c);

        adj[x].push_back({y,c});

        adj[y].push_back({x,c});

    }

    prim(adj,n);

    return 0;

}
