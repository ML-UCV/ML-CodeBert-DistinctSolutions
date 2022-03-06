#include <bits/stdc++.h>


using namespace std;

ifstream f("apm.in");

ofstream g("apm.out");

vector<pair<int,pair<int,int>>> e;

vector <pair<int,int>> rez;

int n,m,cost,t[200005],rang[200005];

int reprezentant(int x)

{

    if(t[x]!=x)

    {

        return reprezentant(t[x]);

    }

    return t[x];

}

bool uneste(int x, int y)

{

    x=reprezentant(x);

    y=reprezentant(y);

    if(x==y)

    {

        return false;

    }

    if(rang[x]>rang[y])

    {

        t[y]=x;

        rang[x]+=rang[y];

        rang[y]=0;

        return true;

    }

    t[x]=y;

    rang[y]+=rang[x];

    rang[x]=0;

    return true;

}

void apm()

{

    for(auto it : e)

    {

        int x=it.second.first;

        int y=it.second.second;

        if(t[x]!=t[y])

        {

            if(uneste(x,y))

            {

                cost+=it.first;

                rez.push_back(it.second);

            }

        }

    }

}

int main()

{

    f>>n>>m;

    for(int i=1;i<=m;i++)

    {

        int x,y,c;

        f>>x>>y>>c;

        e.push_back({c,{x,y}});

    }

    sort(e.begin(),e.end());

    for(int i=1;i<=n;i++)

    {

        t[i]=i;

        rang[i]=1;

    }

    apm();

    g<<cost<<'\n'<<rez.size()<<'\n';

    for(auto it : rez)

    {

        g<<it.first<<' '<<it.second<<'\n';

    }

    return 0;

}
