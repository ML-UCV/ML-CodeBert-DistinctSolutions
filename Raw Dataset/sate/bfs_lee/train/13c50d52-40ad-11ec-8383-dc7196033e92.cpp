#include <bits/stdc++.h>
#define nMax 30010
#define pereche pair<int,int>
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

vector<pereche>v[30010];
queue<pereche>q;

int dist[nMax];
int n,m,xs,ys,a,b,c;
int main()
{
    fin>>n>>m>>xs>>ys;
    for(; m; m--)
    {
        fin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    q.push({dist[xs],xs});
    dist[xs]=-1;
    while(q.size())
    {
        tie(c,a)=q.front();
        q.pop();
        dist[a]+=c;
        if(a==ys)break;
        //fout<<a<<' '<<c<<'\n';
        for(auto vec:v[a])
        {
            if(!dist[vec.first])
            {
                if(vec.first>a)
                    q.push({dist[a]+vec.second,vec.first});
                else
                    q.push({dist[a]-vec.second,vec.first});
            }
        }
    }
    fout<<dist[ys]+1;
    return 0;
}
