#include <fstream>
#include <vector>
std::ifstream fin("ctc.in");

std::ofstream fout("ctc.out");

int n,m,k,cmp,ts[100002],use[100002];

std::vector<std::vector<int>> V,Vt,cnxt;

void DFS(int N)

{

    use[N]=1;

    for(int i=0; i<(int)V[N].size(); i++)

        if(!use[V[N][i]])

            DFS(V[N][i]);

    ts[++k]=N;

}

void DFSt(int N,int cmp)

{

    use[N]=2;

    cnxt[cmp].push_back(N);

    for(int i=0; i<(int)Vt[N].size(); i++)

        if(use[Vt[N][i]]==1)

            DFSt(Vt[N][i],cmp);

}

int main()

{

    fin>>n>>m;

    V.resize(n+2);

    Vt.resize(n+2);

    cnxt.resize(n+2);

    for(int i=1; i<=m; i++)

    {

        int x,y;

        fin>>x>>y;

        V[x].push_back(y);

        Vt[y].push_back(x);

    }

    for(int i=1; i<=n; i++)

        if(!use[i])

            DFS(i);

    for(int i=n; i>=1; i--)

        if(use[ts[i]]==1)

            DFSt(ts[i],++cmp);

    fout<<cmp<<"\n";

    for(int i=1; i<=cmp; i++)

    {

        for(int j=0; j<(int)cnxt[i].size(); j++)

            fout<<cnxt[i][j]<<" ";

        fout<<"\n";

    }

    return 0;

}
