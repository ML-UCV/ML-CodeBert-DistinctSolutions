#include <iostream>
#include<bits/stdc++.h>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");

struct muchie

{

    int c,nod1,nod2;

};

muchie edge[400005];

int dad[200005],grad[200005],n,m;

vector<pair<int,int> > sol;

int cost=0;

bool cmp(muchie a,muchie b)

{

    return a.c<b.c;

}

int root(int node)

{

    while(dad[node])

        node=dad[node];

    return node;

}

void unite(int x,int y)

{

    if(grad[x]>grad[y])

    {

        dad[y]=x;

    }

    else

    {

        dad[x]=y;

        if(grad[y]==grad[x])

            grad[y]++;

    }

}

int main()

{

    f>>n>>m;

    for(int i=1; i<=m; i++)

    {

        f>>edge[i].nod1>>edge[i].nod2>>edge[i].c;

    }



    sort(edge+1,edge+m+1,cmp);

    for(int i=1;i<=m;i++)

    {

        int x=root(edge[i].nod1);

        int y=root(edge[i].nod2);

        if(x!=y)

        {

            unite(x,y);

            sol.push_back({edge[i].nod1,edge[i].nod2});

            cost=cost+edge[i].c;

        }



    }

    g<<cost<<'\n';

    g<<sol.size()<<'\n';

    for(int i=0;i<sol.size();i++)

    {

        g<<sol[i].first<<" "<<sol[i].second<<'\n';

    }







}
