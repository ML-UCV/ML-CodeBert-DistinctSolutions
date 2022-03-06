#include <fstream>
#include <iostream>
#include <vector>
#include <stack>






using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



stack<int> S;

vector<int> G[100005], tG[100005], CTC[100005];

int N, M, NrCTC;

int vizitat[100005];



void Read()

{

    f >> N >> M;

    for (int i = 1; i <= M; i++) {

        int x, y;

        f >> x >> y;

        G[x].push_back(y);

        tG[y].push_back(x);

    }

}

void DFSP(int Nod)

{

    vizitat[Nod] = 1;

    for (unsigned int i = 0; i < G[Nod].size(); i++) {

        int vecin = G[Nod][i];

        if (!vizitat[vecin])

            DFSP(vecin);

    }

    S.push(Nod);

}

void DFSM(int Nod)

{

    vizitat[Nod] = 2;

    CTC[NrCTC].push_back(Nod);

    for (unsigned int i = 0; i < tG[Nod].size(); i++) {

        int vecin = tG[Nod][i];

        if (vizitat[vecin] == 1)

            DFSM(vecin);

    }

}

void Kosoraju()

{

    for (int i = 1; i <= N; i++)

        if (!vizitat[i])

            DFSP(i);

    while (!S.empty()) {

        int Nod = S.top();

        cout << Nod << " ";

        if (vizitat[Nod] == 1) {

            NrCTC++;

            DFSM(Nod);

        }

        S.pop();

    }

}

void Print()

{

    g << NrCTC << "\n";

    for (int i = 1; i <= NrCTC; i++) {

        for (unsigned int j = 0; j < CTC[i].size(); j++)

            g << CTC[i][j] << " ";

        g << "\n";

    }

}

int main()

{

    Read();

    Kosoraju();

    Print();

    return 0;

}
