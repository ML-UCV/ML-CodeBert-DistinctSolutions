#include<fstream>
#include<vector>
#include<stack>
using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

vector<vector<int>>G,CC;

vector<int>niv,L,C;

vector<bool>inS;

stack<int>S;

int n,m,k,nv;

void Citire()

{

    fin>>n>>m;

    G.resize(n+1);

    L.resize(n+1);

    inS.resize(n+1);

    niv.resize(n+1);

    for(int i=1;i<=m;i++)

    {

        int x,y;

        fin>>x>>y;

        G[x].push_back(y);

    }

}

void Tarjan(int x)

{

    niv[x] = L[x] = ++nv;

    S.push(x);

    inS[x] = true;

    for(auto y : G[x])

    {

        if(niv[y]==0)

        {

            Tarjan(y);

            L[x]=min(L[x],L[y]);

        }

        else

        {

            if(inS[y]==true)

                L[x]=min(L[x],niv[y]);

        }

    }

    if(niv[x]==L[x])

    {

        C.clear();

        int y=-1;

        while(x!=y)

        {

            y=S.top();

            S.pop();

            C.push_back(y);

            inS[y]=false;

        }

        CC.push_back(C);

    }

}

void Afisare()

{

    fout<<CC.size()<<'\n';

    for(auto V : CC)

    {

        for(auto x : V)

            fout<<x<<" ";

        fout<<'\n';

    }

}

int main()

{

    Citire();

    for(int i=1;i<=n;i++)

        if(!niv[i])

            nv=0,Tarjan(i);

    Afisare();

    return 0;

}
