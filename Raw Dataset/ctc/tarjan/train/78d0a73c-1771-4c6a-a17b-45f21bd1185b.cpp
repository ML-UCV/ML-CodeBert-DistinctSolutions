#include <fstream>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



vector<int> graf[100005];

int n, m, index;

vector<vector<int> > totSol;

bool viz[100005], inStack[100005];

int low[100005], niv[100005];

stack<int> S;



void citire()

{

    f>>n>>m;

    int x, y;

    for(int i = 0; i<m; i++)

    {

        f>>x>>y;

        graf[x].push_back(y);

    }

}



void dfs(int currNode)

{

    viz[currNode] = true;

    S.push(currNode);

    inStack[currNode] = true;

    low[currNode] = index;

    niv[currNode] = index;

    index++;

    for(int i : graf[currNode])

    {

        if(!viz[i])

        {

            dfs(i);

        }

        if(inStack[i])

            low[currNode] = min(low[i], low[currNode]);

    }

    if(low[currNode] == niv[currNode])

    {

        vector<int> sol;

        int el;

        do

        {

            el = S.top();

            S.pop();

            sol.push_back(el);

            inStack[el] = false;

        }while(el != currNode);

        totSol.push_back(sol);

    }

}



void parcurgere()

{

    for(int i = 1; i<=n; ++i)

    {

        if(!viz[i])

            dfs(i);

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

    parcurgere();

    afisare();

    return 0;

}
