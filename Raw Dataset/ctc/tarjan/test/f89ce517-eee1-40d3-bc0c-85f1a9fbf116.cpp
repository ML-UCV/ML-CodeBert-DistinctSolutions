#include<fstream>
#include<vector>
#include<stack>
using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

vector<vector<int>>G;

vector<vector<int>>CC;

vector<int>C;

stack<int>S;

int L[100001],niv[100001];

bool InS[100001];

int n,m,nv;

void Citire()

{

    fin>>n>>m;

    G.resize(n+1);

    for(int i=1;i<=m;i++)

    {

        int x,y;

        fin>>x>>y;

        G[x].push_back(y);

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

void Tarjan(int x)

{

    nv++;

    L[x]=nv;

    niv[x]=nv;

    S.push(x);

    InS[x]=true;

    for(auto y : G[x])

    {

        if(niv[y]==0)

        {

            Tarjan(y);

            L[x]=min(L[x],L[y]);

        }

        else

        {

            if(InS[y])

                L[x]=min(L[x],niv[y]);

        }

    }

    if(L[x]==niv[x])

    {

        C.clear();

        int y=-1;

        while(x!=y)

        {

            y=S.top();

            InS[y]=false;

            C.push_back(y);

            S.pop();

        }

        CC.push_back(C);

    }

}

int main()

{

    Citire();

    for(int i=1;i<=n;i++)

        if(!niv[i])

            nv=0,Tarjan(i);

    Afisare();

}
