#include <bits/stdc++.h>

using namespace std;
ifstream in("sate.in");
ofstream out("sate.out");
struct muchie
{
    int d;
    int c;
};
const int nx= 30002;
vector < muchie > v[nx];
int n,m,start,stop;
int dist[nx];
void bfs ()
{
    queue < int > q;
    dist[start]=0;
    q.push(start);
    while(!q.empty())
    {
        int i=q.front();
        int d=dist[i];
        q.pop();
        for(vector < muchie > :: iterator it=v[i].begin(); it!=v[i].end(); it++)
            if(dist[it->d]==0)
            {
                if(it->d < i)
                    dist[it->d]=d-(it->c);
                else dist[it->d]=d+(it->c);
                if(it->d==stop)
                {
                    out<<dist[stop];
                    return;
                }
                q.push(it->d);
            }
    }
}
int main()
{
    in>>n>>m>>start>>stop;
    for(;m;m--)
    {
        int i,j,c;
        in>>i>>j>>c;
        v[i].push_back({j,c});
        v[j].push_back({i,c});
    }
    bfs();
    return 0;
}
