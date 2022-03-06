#include <stack>
#include <vector>
#include <fstream>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



int n,m,Nr,viz[100001];

vector<int>G[100001],GT[100001],sol[100001];

stack<int>S;



void dfs1(int nod)

{

    viz[nod]=1;

    for(int i=0;i<G[nod].size();i++)

    {

        int vecin=G[nod][i];

        if(!viz[vecin])

            dfs1(vecin);

    }

    S.push(nod);

}



void dfs2(int nod)

{

    viz[nod]=2;

    sol[Nr].push_back(nod);

    for(int i=0;i<GT[nod].size();i++)

    {

        int vecin=GT[nod][i];

        if(viz[vecin]==1)

            dfs2(vecin);

    }

}



int main()

{

    int x,y;

    f>>n>>m;

    for(int i=1;i<=m;i++)

    {

        f>>x>>y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }

    for(int i=1;i<=n;i++)

    {

        if(!viz[i])dfs1(i);

    }

    while(!S.empty())

    {

        int Nod=S.top();

        if(viz[Nod]==1)

        {

            Nr++;

            dfs2(Nod);

        }

        S.pop();

    }



    g<<Nr;

    for(int i=0;i<=Nr;i++)

    {

        for(int j=0;j<sol[i].size();j++)g<<sol[i][j]<<" ";



        g<<'\n';

    }

    return 0;

}
