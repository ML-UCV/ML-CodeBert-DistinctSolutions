#include <fstream>
#include <vector>
#include <stack>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int NMAX = 100005;



stack < int > S;

vector < int > G[NMAX], GT[NMAX], CTC[NMAX];



int n, m, nrCTC;

int vis[NMAX];



void read()

{

    fin >> n >> m;

    for (int i = 1; i <= m; i++){

        int x, y;

        fin >> x >> y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }

}



void DFS(int nod)

{

    vis[nod] = 1;

    for (unsigned int i = 0; i < G[nod].size(); i++){

        int vecin = G[nod][i];

        if (!vis[vecin])

            DFS(vecin);

    }

    S.push(nod);

}



void DFSM(int nod)

{

    vis[nod] = 2;

    CTC[nrCTC].push_back(nod);

    for (unsigned int i = 0; i < GT[nod].size(); i++){

        int vecin = GT[nod][i];

        if (vis[vecin] == 1)

            DFSM(vecin);

    }



}



void solve()

{

    for (int i = 1; i <= n; i++)

        if (!vis[i])

            DFS(i);



    while (!S.empty()){

        int nod = S.top();

        if (vis[nod] == 1){

            nrCTC++;

            DFSM(nod);

        }

        S.pop();

    }

}



void print()

{

    fout << nrCTC << "\n";

    for (int i = 1; i <= nrCTC; i++){

        for (unsigned int j = 0; j < CTC[i].size(); j++)

            fout << CTC[i][j] << " ";

        fout << "\n";

    }

}



int main()

{

    read();

    solve();

    print();

    return 0;

}
