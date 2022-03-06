#include <fstream>
#include <vector>
#include <bitset>
#include <iostream>
#include <deque>


using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

int g,low[100005],niv[100005],ctc,n,m,x,y,i,j;

bitset<100005> IQ;

deque<int> q;

vector <int> L[100005],C[100005];

void dfs(int nod)

{

    g++;

    low[nod]=g;

    niv[nod]=g;

    IQ[nod]=1;

    q.push_back(nod);

    for(int i=0; i<L[nod].size(); i++)

    {

        int vecin=L[nod][i];

        if(niv[vecin]==0){

            dfs(vecin);

            low[nod]=min(low[nod],low[vecin]);

        }else if(IQ[vecin]==1){

            low[nod]=min(low[nod],low[vecin]);

        }

    }

    if(low[nod]==niv[nod]){

        ctc++;

        while(q.back()!=nod){

            C[ctc].push_back(q.back());

            IQ[q.back()]=0;

            q.pop_back();

        }

        C[ctc].push_back(q.back());

        IQ[q.back()]=0;



    q.pop_back();

    }

}

int main()

{

    fin>>n>>m;

    for(; m--;)

    {

        fin>>x>>y;

        L[x].push_back(y);

    }

    for(i=1; i<=n; i++)

    {

        if(niv[i]==0)

        {

            dfs(i);

        }

    }

    fout<<ctc<<"\n";

    for(i=1;i<=ctc;i++){

        for(j=0;j<C[i].size();j++)

            fout<<C[i][j]<<" ";

            fout<<"\n";

    }

}
