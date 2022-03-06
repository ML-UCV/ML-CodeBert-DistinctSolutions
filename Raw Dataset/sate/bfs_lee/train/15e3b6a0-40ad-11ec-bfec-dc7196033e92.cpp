#include <bits/stdc++.h>

using namespace std;


ifstream f("sate.in");
ofstream g("sate.out");

const int nmax = 30001;

int n,m,x,y;
vector <pair <int,int> > adj[nmax];
vector <int> visited(nmax);
queue <int> q;

void addedge (vector<pair <int,int> > adj[], int a, int b, int c)
{
    adj[a].push_back(make_pair(b,c));
    adj[b].push_back(make_pair(a,c));
}



void citire()
{
    f>>n>>m>>x>>y;
    int a,b,c;
    int i;
    for(i=1;i<=m;i++)
    {
        f>>a>>b>>c;
        addedge(adj,a,b,c);
    }
}

int bfs()
{
    int c = x;
    int i;
    q.push(c);
    visited[c] = 0;
    while( !q.empty())
    {
        if(visited[y])
            return visited[y];
        c = q.front();
        q.pop();
        for( i = 0; i< adj[c].size(); i++)
        {
            if(!visited[adj[c][i].first])
            {
                if(c < adj[c][i].first)
                    visited[adj[c][i].first] = visited[c]+adj[c][i].second;
                else
                     visited[adj[c][i].first] = visited[c]-adj[c][i].second;
                q.push(adj[c][i].first);
            }


        }
    }
}





int main()
{
    citire();
    g<<bfs();
}
