#include <bits/stdc++.h>




using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");

int n,m;

int cost;

int parent[200005];

int card[200005];

vector<pair<int,int> >ans;

priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;

int find_parent(int pos)

{



    if (parent[pos]!=pos)

    {

        parent[pos]=find_parent(parent[pos]);

        return parent[pos];

    }

    return pos;

}

void reuniune(int x,int y)

{







    x=find_parent(x);

    y=find_parent(y);



    if (card[x]<card[y])

        swap(x,y);

    parent[y]=x;

    card[x]+=card[y];

}

void compute_answer()

{

    while(ans.size()!=n-1)

    {

        int c=pq.top().first;

        int x=pq.top().second.first;

        int y=pq.top().second.second;

        pq.pop();

        if(find_parent(x)==find_parent(y))

            continue;

        ans.push_back({x,y});

        cost+=c;

        reuniune(x,y);

    }

}

int main()

{

    fin>>n>>m;

    int c,x,y;

    for(int i=1;i<=m;i++)

    {

        fin>>x>>y>>c;

        pq.push({c,{x,y}});

    }

    for(int i=1;i<=n;i++)

    {



        parent[i]=i;

        card[i]=i;

    }

    compute_answer();

    fout<<cost<<"\n";

    fout<<n-1<<"\n";

    for(int i=0;i<ans.size();i++)

        fout<<ans[i].first<<" "<<ans[i].second<<"\n";

    return 0;

}
