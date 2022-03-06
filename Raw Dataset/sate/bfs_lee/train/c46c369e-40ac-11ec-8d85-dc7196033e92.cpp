
#include<bits/stdc++.h>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

vector<pair<int, int>> graph[30001];
int distances[30001];
int visited[30001];

int main()
{
    int n,m,x,y,i,d,curr,neigh,distance,a,b;
    fin>>n>>m>>x>>y;
    for(i=0;i<m;i++){
        fin>>a>>b>>d;
        graph[a].push_back({b, d});
        graph[b].push_back({a, -d});
    }
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    int found = 0;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        for(auto i:graph[curr]){
            neigh = i.first;
            distance = i.second;
            if(!visited[neigh]){
                visited[neigh] = 1;
                distances[neigh] = distances[curr] + distance;
                q.push(neigh);

                if(neigh == y){
                    fout<<distances[y]<<"\n";
                    cout<<distances[y];
                    found = 1;
                    break;
                }
            }
        }
        if(found){
           break;
        }
    }


    return 0;
}
/*
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

int n, m, x, y;
vector< pair<int, int> > adj[30005];
int dist[30005];
bool viz[30005];

void BFS()
{
    int curr, next, distanta;
    queue<int> queue;
    queue.push(x);
    viz[x] = true;
    while (!queue.empty())
    {
        curr = queue.front();
        queue.pop();
        for (auto rel : adj[curr])
        {
            next = rel.first;
            distanta = rel.second;
            if (!viz[next])
            {
                viz[next] = true;
                dist[next] = dist[curr] + distanta;

                queue.push(next);

                if (next == y)
                {
                    g << dist[y] << "\n";
                    return;
                }
            }
        }
    }
}

int main()
{

    f >> n >> m >> x >> y;
    while(m--)
    {
        int a, b, distanta;
        f >> a >> b >> distanta;
        adj[a].push_back({b, distanta});
        adj[b].push_back({a, -distanta});
    }
    BFS();
    return 0;
}
*/
