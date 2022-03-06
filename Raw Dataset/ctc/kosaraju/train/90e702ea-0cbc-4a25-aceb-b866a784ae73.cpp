#include <fstream>
#include <vector>
#include <stack>
#include <string.h>




using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");



int n, m, viz[100005], vizT[100005], ct;

vector <int> muchii[100005];

vector <int> muchiiT[100005];

vector <int> sol[100005];

stack <int> S;



void Citire()

{

    int i, x, y;

    fin >> n >> m;

    for (i = 1; i <= m; i++)

    {

        fin >> x >> y;

        muchii[x].push_back(y);

        muchiiT[y].push_back(x);

    }

}



void DFS(int x)

{

    int i, y;

    viz[x] = 1;

    for (i = 0; i < muchii[x].size();i++)

        if (viz[muchii[x][i]] == 0)

            DFS(muchii[x][i]);

    S.push(x);

}





void DFST(int x)

{

    int y, i;

    vizT[x] = 1;

    sol[ct].push_back(x);

    for (i = 0; i < muchiiT[x].size(); i++)

        if (vizT[muchiiT[x][i]] == 0)

            DFST(muchiiT[x][i]);



}





void CompTareConexe()

{

    int i, x, j;

    for (i = 1; i <= n; i++)

        if (viz[i]==0)

            DFS(i);



    while (S.empty()==0)

    {

        if (vizT[S.top()]==0)

        {

            ct++;

            DFST(S.top());

        }

        S.pop();

    }



    fout << ct << "\n";

    for (i = 1; i <= ct; i++)

    {

        for (j = 0; j < sol[i].size(); j++)

            fout << sol[i][j] << " ";

        fout << "\n";

    }



}





int main()

{

    Citire();

    CompTareConexe();



    return 0;

}
