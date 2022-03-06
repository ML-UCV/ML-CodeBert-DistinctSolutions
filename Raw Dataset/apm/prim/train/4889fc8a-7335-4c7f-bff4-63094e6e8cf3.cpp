#include <bits/stdc++.h>




using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");

int n,m;

int cost;

bool ap[200005];

vector<pair<int,int> >nod[200005],ans;

priority_queue<pair<int,pair<int,int> > ,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;

void add_edges_of(int x)

{



    ap[x]=true;

    int y,c;

    for(int i=0;i<nod[x].size();i++)

    {

        y=nod[x][i].first;

        c=nod[x][i].second;

        if(ap[y])

            continue;

        pq.push({c,{y,x}});

    }

}

void compute_answer()

{

    add_edges_of(1);

    int c,x,y;

    while(ans.size()!=n-1)

    {

        c=pq.top().first;

        y=pq.top().second.first;

        x=pq.top().second.second;

        pq.pop();

        if (ap[y])

            continue;

        cost+=c;

        ans.push_back({x,y});

        add_edges_of(y);

    }

}

int main()

{

    fin>>n>>m;

    int c,x,y;

    for(int i=1;i<=m;i++)

    {

        fin>>x>>y>>c;

        nod[x].push_back({y,c});

        nod[y].push_back({x,c});

    }

    compute_answer();



    fout<<cost<<"\n";

    fout<<n-1<<"\n";

    for(int i=0;i<ans.size();i++)

        fout<<ans[i].first<<" "<<ans[i].second<<"\n";

    return 0;

}
