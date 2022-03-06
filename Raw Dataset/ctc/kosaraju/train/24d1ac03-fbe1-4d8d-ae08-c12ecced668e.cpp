#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int DIM = 100005;



int n,m,x,y,viz[DIM],cnt=0;



stack <int> St;



vector <int> G[DIM];

vector <int> P[DIM];

vector <int> Sol[DIM];



void DFS1(int nod)

{

    viz[nod]=1;

    for(auto it : G[nod])

    {

        if(!viz[it])

            DFS1(it);

    }

    St.push(nod);

}



void Read()

{

    fin>>n>>m;

    for(int i=1;i<=m;i++)

    {

        fin>>x>>y;

        G[x].push_back(y);

        P[y].push_back(x);

    }

}



void DFS2(int nod)

{

    viz[nod]=1;

    Sol[cnt].push_back(nod);

    for(auto it : P[nod])

    {

        if(!viz[it])

            DFS2(it);

    }

}



void Solve()

{

    for(int i=1;i<=n;i++)

    {

        if(!viz[i])

            DFS1(i);

    }

    memset(viz,0,sizeof(viz));

    while(!St.empty())

    {

        int k=St.top();

        if(!viz[k])

        {

            cnt++;

            DFS2(k);

        }

        St.pop();

    }

}



void Print()

{

    fout<<cnt<<'\n';

    for(int i=1;i<=cnt;i++)

    {

        for(auto it : Sol[i])

            fout<<it<<" ";

        fout<<'\n';

    }

}



int main()

{

    Read();

    Solve();

    Print();

}
