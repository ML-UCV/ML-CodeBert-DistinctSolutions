#include    <iostream>
#include    <fstream>
#include    <vector>
#include    <queue>
#include    <cstring>
#include    <stack>




using namespace std;



ifstream in("ctc.in");

ofstream out("ctc.out");



const int Nmax = 1e5 + 5;

vector <int> G[Nmax], GT[Nmax];

stack <int> S;

int Viz[Nmax];

int n, m, Nr_CTC;

vector <int> Rez[Nmax];



void Read()

{

    in>>n>>m;

    for(int i = 1; i <= m; i++)

    {

        int x, y;

        in>>x>>y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }

}



void DFS(int nod)

{

    Viz[nod] = 1;

    for(auto vec : G[nod])

        if(!Viz[vec])

          DFS(vec);

    S.push(nod);

}



void DFS_T(int nod)

{

    Viz[nod] = 2;

    Rez[Nr_CTC].push_back(nod);

    for(auto vec : GT[nod])

        if(Viz[vec] == 1)

           DFS_T(vec);

}



void Solve()

{

    for(int i = 1; i <= n; i++)

        if(!Viz[i])

           DFS(i);

    while(!S.empty())

    {

        int Nod = S.top();

        S.pop();

        if(Viz[Nod] == 1)

        {

            Nr_CTC++;

            DFS_T(Nod);

        }

    }

}



void Print()

{

    out<<Nr_CTC<<'\n';

    for(int i = 1; i <= Nr_CTC; i++, out<<'\n')

        for(auto it : Rez[i])

           out<<it<<' ';

}



int main()

{

    Read();

    Solve();

    Print();

}
