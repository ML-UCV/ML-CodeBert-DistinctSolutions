#include <bits/stdc++.h>


using namespace std;

ifstream f("ctc.in");

ofstream g("ctc.out");

const int dim=1e5+10;

typedef long long ll;

typedef pair<int,int> pi;

int t,T,n,m,a,b,cnt;



vector < int > V[dim],A,viz(dim,0),VT[dim],B[dim];



void DFS(int nod)

{

    viz[nod]=1;

    for(unsigned int vecin:V[nod])

    {

        if(!viz[vecin])

            DFS(vecin);

    }

    viz[nod]=2;

    A.push_back(nod);

}



void DFST(int nod)

{

    B[cnt].push_back(nod);

    viz[nod]=1;

    for(unsigned int vecin:VT[nod])

    {

        if(!viz[vecin])

            DFST(vecin);

    }

    viz[nod]=2;

}



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    f>>n>>m;

    for(int i=1;i<=m;i++)

    {

        f>>a>>b;

        V[a].push_back(b);

        VT[b].push_back(a);

    }

    for(int i=1;i<=n;i++)

    if(!viz[i]) DFS(i);



    for(int i=1;i<=n;i++) viz[i]=0;



    reverse(A.begin(),A.end());

    for(unsigned int x:A)

    if(!viz[x])

    {

        cnt++;

        DFST(x);

    }

    g<<cnt<<'\n';

    for(int i=1;i<=cnt;i++)

    {

        for(unsigned int x:B[i])

            g<<x<<' ';

        g<<'\n';

    }







    return 0;

}
