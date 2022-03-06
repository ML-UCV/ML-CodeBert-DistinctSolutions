#include <iostream>
#include <fstream>
#include <vector>


using namespace std;



ifstream in("ctc.in");

ofstream out("ctc.out");



vector<vector<int> > G, GT, CTC;

short viz[100005];

int TS[100005];

int N, M, k, nrCTC;



void citire()

{

    in >> N >> M;

    G.resize(N + 2);

    GT.resize(N + 2);

    CTC.resize(N + 2);

    int x, y;

    for(int i = 1; i <= M; i++)

    {

        in >> x >> y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }

}



void DFS1(int z)

{

    viz[z] = 1;

    for(int i = 0; i < G[z].size(); i++)

    {

        int Vecin = G[z][i];

        if(!viz[Vecin])

            DFS1(Vecin);

    }

    TS[++k] = z;

}



void DFS2(int z)

{

    viz[z] = 2;

    CTC[nrCTC].push_back(z);

    for(int i = 0; i < GT[z].size(); i++)

    {

        int Vecin = GT[z][i];

        if(viz[Vecin] == 1)

            DFS2(Vecin);

    }

}



int main()

{

    citire();

    for(int i = 1; i <= N; i++)

        if(!viz[i])

            DFS1(i);



    for(int i = N; i >= 1; i--)

    {

        if(viz[TS[i]] == 1)

        {

            nrCTC++;

            DFS2(TS[i]);

        }

    }



    out << nrCTC << '\n';



    for(int i = 1; i <= nrCTC; i++)

    {

        for(int j = 0; j < CTC[i].size(); j++)

            out << CTC[i][j] << ' ';

        out << '\n';

    }



}
