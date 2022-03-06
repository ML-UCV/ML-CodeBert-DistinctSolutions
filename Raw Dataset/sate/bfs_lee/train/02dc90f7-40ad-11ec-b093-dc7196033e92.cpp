#include <bits/stdc++.h>

using namespace std;
bitset<100030>ap;
int n,m,x,y,p1,p2,c;
vector<pair<int,int> >nod[30005];
int main()
{
    ifstream fin("sate.in");
    ofstream fout("sate.out");
    fin>>n>>m>>x>>y;
    for(int i=1;i<=m;i++)
    {
        fin>>p1>>p2>>c;
        nod[p1].push_back({p2,c});
        nod[p2].push_back({p1,-1*c});
    }
    priority_queue<pair<int,int> >pq;
    pq.push({0,x});
    while(!pq.empty())
    {
        int pos=pq.top().second;
        int dist=pq.top().first;
        pq.pop();
        if(ap[pos])
            continue;
        ap[pos]=1;
        if(pos==y)
        {
            fout<<abs(dist);
            return 0;
        }
        for(int i=0;i<nod[pos].size();i++)
        {
            if(ap[nod[pos][i].first])
                continue;
            pq.push({dist+nod[pos][i].second,nod[pos][i].first});
        }
    }
    return 0;
}
