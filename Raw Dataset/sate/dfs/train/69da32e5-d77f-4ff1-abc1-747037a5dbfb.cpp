#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

int seen[40000], d = 0, y;

struct drumuri
{
    int vecin;
    int dis;
};



void DFS(int nod, vector<drumuri> v[40000])
{
    if(nod == y)
    {
        out<<d;
        exit(0);
    }

    seen[nod] = -1;
    for(int j = 0; j<v[nod].size(); j++)
        if(seen[v[nod][j].vecin]==0)
        {
            d+=v[nod][j].dis;
            DFS(v[nod][j].vecin, v);
            d-=v[nod][j].dis;
        }
}

int main()
{
    vector<drumuri> v[40000];
    int n, m, a, b, i, x, dist;
    in>>n>>m>>x>>y;
    for(i = 0; i<m;i++)
    {
        in>>a>>b>>dist;

        drumuri dr = {b, dist};
        v[a].push_back(dr);

        drumuri dr2 = {a, -dist};
        v[b].push_back(dr2);
    }
    DFS(x, v);
    return 0;
}
