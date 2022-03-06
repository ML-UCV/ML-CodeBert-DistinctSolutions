#include <bits/stdc++.h>
using namespace std;

ifstream f("apm.in");

ofstream g("apm.out");

const int NMAX=200005,MMAX=400005;

int n,m,answer,status[NMAX],parent[NMAX];

vector<int>solution;

struct edge

{

    int x,y,c;

} v[MMAX];

bool cmp(edge A,edge B)

{

    return A.c<B.c;

}

int findRoot(int node)

{

    if(parent[node]==node)

        return node;

    parent[node]=findRoot(parent[node]);

    return parent[node];

}

void unionSets(int node1,int node2)

{

    node1=findRoot(node1);

    node2=findRoot(node2);

    if(node1==node2)

        return;

    if(status[node1]<status[node2])

        swap(node1,node2);

    if(status[node1]==status[node2])

        status[node1]++;

    parent[node2]=node1;

}

int main()

{

    f>>n>>m;

    for(int i=1; i<=n; i++)

    {

        parent[i]=i;

        status[i]=1;

    }

    for(int i=1; i<=m; i++)

        f>>v[i].x>>v[i].y>>v[i].c;

    sort(v+1,v+m+1,cmp);

    for(int j=1; j<=m; j++)

        if(findRoot(v[j].x)!=findRoot(v[j].y))

        {

            answer+=v[j].c;

            solution.push_back(j);

            unionSets(v[j].x,v[j].y);

        }

    g<<answer<<"\n"<<n-1<<"\n";

    for(int i=0; i<solution.size(); i++)

        g<<v[solution[i]].x<<" "<<v[solution[i]].y<<"\n";

    return 0;

}
