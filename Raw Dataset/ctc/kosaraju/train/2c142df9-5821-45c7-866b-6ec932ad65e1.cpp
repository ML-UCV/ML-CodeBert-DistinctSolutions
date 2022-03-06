#include <bits/stdc++.h>


using namespace std;

ifstream fi("ctc.in");

ofstream fo("ctc.out");

vector <int> V[100001],T[100001];

stack <int> FIN;

vector <int> R[100001];

int n,m,rez;

bool viz[100001],check[100001];

void dfs(int nod)

{

    if(viz[nod])

        return;

    viz[nod]=1;

    for(auto i:V[nod])

        dfs(i);

    FIN.push(nod);

}

void dfs1(int nod)

{

    if(check[nod])

        return;

    check[nod]=1;

    for(auto i:T[nod])

        dfs1(i);

    R[rez].push_back(nod);

}

int main()

{

    fi>>n>>m;

    for(int i=1;i<=m;i++)

    {

        int a,b;

        fi>>a>>b;

        V[a].push_back(b);

        T[b].push_back(a);

    }

    for(int i=1;i<=n;i++)

    {

        if(!viz[i])

            dfs(i);

    }

    while(!FIN.empty())

    {

        int start=FIN.top();

        if(check[start]==0)

        {

            rez++;

            dfs1(start);

        }

        FIN.pop();



    }

    fo<<rez<<'\n';

    for(int i=1;i<=rez;i++)

    {

        for(auto j:R[i])

            fo<<j<<' ';

        fo<<'\n';

    }
    return 0;

}
