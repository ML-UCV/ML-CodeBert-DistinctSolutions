#include <iostream>
#include <bits/stdc++.h>
using namespace std;

ifstream f ("ctc.in");

ofstream g ("ctc.out");

int n, m;

vector<int> v[100005];

vector<int> vr[100005];

vector<int> sk;

int viz[100005], viz2[100005];

vector<vector<int>> componente;
void dfs(int x)

{

    if(viz[x]==0)

    {

        viz[x]=1;

        for(int i=0; i<v[x].size(); i++)

        {

            if(viz[v[x][i]]==0)

                dfs(v[x][i]);

        }

        sk.push_back(x);

    }

}

void dfs_reverse(int x, int index)

{

    if(viz2[x]==0)

    {

        viz2[x]=1;

        componente[index].push_back(x);

        for(int i=0; i<vr[x].size(); i++)

        {

            if(viz2[vr[x][i]]==0)

                dfs_reverse(vr[x][i], index);

        }

    }

}



int main()

{

    f>>n>>m;

    for(int i=0; i<m; i++)

    {

        int x, y;

        f>>x>>y;

        v[x].push_back(y);

        vr[y].push_back(x);

    }



    int modificari=1;

    while(modificari==1)

    {

        modificari=0;

        for(int i=1; i<=n; i++)

        {

            if(viz[i]==0)

            {

                dfs(i);

                modificari=1;

            }

        }

    }



    int index=0;

    reverse(sk.begin(), sk.end());

    modificari=1;

    while(modificari==1)

    {

        modificari=0;

        for(int i=0; i<n; i++)

        {

            if(viz2[sk[i]]==0)

            {

                vector<int> r;

                componente.push_back(r);

                dfs_reverse(sk[i], index);

                modificari=1;

                index++;

            }

        }

    }

    g<<componente.size()<<"\n";

    for(int i=0; i<componente.size(); i++)

    {

            for(int j=0; j<componente[i].size(); j++)

            {

                g<<componente[i][j]<<" ";

            }

            g<<"\n";

    }

    return 0;

}
