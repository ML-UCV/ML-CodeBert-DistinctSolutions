#include<bits/stdc++.h>


using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

int n,m,i,a,b,low[100010],niv[100010],l,nr,d[100010];

vector<int> v[100010],s,sol[100010];

void dfs(int nod)

{

    low[nod]=niv[nod]=++l;

    s.push_back(nod);d[nod]=1;

    for(auto it:v[nod])

    {

        if(niv[it]&&d[it]) low[nod]=min(low[nod],niv[it]);

        if(niv[it]==0)

        {

            dfs(it);

            low[nod]=min(low[it],low[nod]);

        }

    }

    if(low[nod]==niv[nod])

    {

        nr++;while(s.back()!=nod) sol[nr].push_back(s.back()),d[s.back()]=0,s.pop_back();

        sol[nr].push_back(s.back()),d[s.back()]=0,s.pop_back();

    }

}



int main()

{

    fin>>n>>m;

    for(i=1;i<=m;i++)

    {

        fin>>a>>b;

        v[a].push_back(b);

    }

    for(i=1;i<=n;i++) if(niv[i]==0) dfs(i);

    fout<<nr<<"\n";

    for(i=1;i<=nr;i++)

    {

        for(auto it:sol[i]) fout<<it<<" ";

        fout<<"\n";

    }

    return 0;

}
