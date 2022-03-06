#include <fstream>
#include <vector>
#include <stack>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



vector<int> graf[100005], grafInvers[100005];

int n, m;

vector<vector<int> > totSol;

vector<int> sol;

int viz[100005];

bool parc;

stack<int> S;



void citire()

{

    f>>n>>m;

    int x, y;

    for(int i = 0; i<m; i++)

    {

        f>>x>>y;

        graf[x].push_back(y);

        grafInvers[y].push_back(x);

    }

}



vector<int> getGraf(int poz)

{

    if(!parc)

        return graf[poz];

    else

        return grafInvers[poz];

}



void dfs(int currNode)

{

    viz[currNode] = parc+1;

    if(parc)

        sol.push_back(currNode);

    for(int i : getGraf(currNode))

    {

        if(viz[i] != parc+1)

        {

            dfs(i);

        }

    }

    if(!parc)

        S.push(currNode);

}



void parcUnu()

{

    for(int i = 1; i<=n; ++i)

    {

        if(viz[i] != parc+1)

            dfs(i);

    }

}



void parcDoi()

{

    parc = 1;

    int nod;

    while(!S.empty())

    {

        nod = S.top();

        S.pop();

        if(viz[nod] != parc+1){

            sol.clear();

            dfs(nod);

            totSol.push_back(sol);

        }

    }

}



void afisare()

{

    g<<totSol.size()<<"\n";

    for(int i = 0; i<totSol.size(); i++)

    {

        for(int j : totSol[i])

        {

            g<<j<<" ";

        }

        g<<"\n";

    }

}



int main()

{

    citire();

    parcUnu();

    parcDoi();

    afisare();

    return 0;

}
