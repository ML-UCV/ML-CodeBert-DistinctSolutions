#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;



ofstream g("ctc.out");

const int NMAX = 100005;

vector < int > G[NMAX], GT[NMAX], result[NMAX];

stack <int > S;

int NrCTC;

int N,M;

int beenThere[NMAX];

int rez[NMAX];



void read()

{

    ifstream f("ctc.in");

    f >> N >> M;

    for(int i = 1; i <= M; i++)

    {

        int x,y;

        f >> x >> y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }

}



void DFS(int Nod){

    beenThere[Nod] = 1;

    for(unsigned int i = 0; i < G[Nod].size();i++){

        int Vecin = G[Nod][i];

        if(!beenThere[Vecin])

            DFS(Vecin);

    }

    S.push(Nod);

}



void DFS_T(int Nod){

    beenThere[Nod] = 2;

    result[NrCTC].push_back(Nod);



    for(unsigned int i = 0; i < GT[Nod].size();i++){

        int Vecin = GT[Nod][i];

        if(beenThere[Vecin] == 1)

            DFS_T(Vecin);

    }

}

void Solve()

{

    for(int i = 1; i <= N;i++){

        if(!beenThere[i])

            DFS(i);

    }

    while(!S.empty()){

        int Nod = S.top();

        cout << Nod << " ";

        if(beenThere[Nod] == 1){

            NrCTC++;

            DFS_T(Nod);

        }

        S.pop();

    }

}



void Print()

{

    g << NrCTC << '\n';



    for(int i = 1; i <= NrCTC;i++){

        for(unsigned int j = 0; j < result[i].size();j++)

            g << result[i][j] << " ";

    g << '\n';

}

}

int main()

{

    read();

    Solve();

    Print();

    return 0;

}
