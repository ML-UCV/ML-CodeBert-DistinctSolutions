#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <vector>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int DIM = 100005;



vector <int> G[DIM];

vector <int> GT[DIM];

vector <int> A[DIM];



int n,m,x,y,ans=0;



stack <int> S;



int viz[DIM];



void Read()

{

    fin>>n>>m;

    for(int i=1;i<=m;i++)

    {

        fin>>x>>y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }

}



void DFS1(int nod)

{

    viz[nod]=1;

    for(unsigned int i=0;i<G[nod].size();i++)

    {

        int vecin=G[nod][i];

        if(!viz[vecin])

            DFS1(vecin);

    }

    S.push(nod);

}



void DFS2(int nod)

{

    viz[nod]=2;

    A[ans].push_back(nod);

    for(unsigned i=0;i<GT[nod].size();i++)

    {

        int vecin=GT[nod][i];

        if(viz[vecin]==1)

            DFS2(vecin);

    }

}



void Solve()

{

    for(int i=1;i<=n;i++)

    {

        if(!viz[i])

            DFS1(i);

    }

    while(!S.empty())

    {

        int nod=S.top();

        if(viz[nod]==1)

        {

            ans++;

            DFS2(nod);

        }

        S.pop();

    }

}



void Print()

{

    fout<<ans<<'\n';

    for(int i=1;i<=ans;i++)

    {

        vector <int> ::iterator it;

        for(it=A[i].begin();it!=A[i].end();it++)

            fout<<*it<<" ";

        fout<<'\n';

    }

}



int main()

{

    Read();

    Solve();

    Print();

}
