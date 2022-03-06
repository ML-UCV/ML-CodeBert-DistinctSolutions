#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;



ifstream in ("ctc.in");

ofstream out("ctc.out");

int n, m, x, y, compAct, mom;

vector < vector <int> > muchii, componente;

vector <int> disc, low, componentaTata;

stack <int> stk;

vector <char> realVal;

void Tarjan(int nod)

{

    low[nod]=disc[nod] = ++mom;

    stk.push(nod);

    for(auto & x : muchii[nod])

    {

        if(disc[x]==-1)

        {

            Tarjan(x);

            low[nod]=min(low[nod], low[x]);

        }

        else

        {

            low[nod]=min(low[nod], disc[x]);

        }

    }



    if(low[nod]==disc[nod])

    {

        componente.push_back( vector<int>());

        while(!stk.empty()&&stk.top()!=nod)

        {

            componente.back().push_back(stk.top());

            disc[stk.top()]+=2*n;

            componentaTata[stk.top()]=componente.size();

            stk.pop();

        }

        componente.back().push_back(stk.top());

        disc[stk.top()]+=2*n;

        componentaTata[stk.top()]=componente.size();

        stk.pop();

    }

}



int main()

{

    in>>n>>m;

    muchii.resize(n+1); componentaTata.resize(n+1, -1);

    disc.resize(n+1, -1); low.resize(n+1, -1); realVal.resize(n+1, 0);

    for(int i=1; i<=m; i++)

    {

        in>>x>>y;

        muchii[x].push_back(y);

    }

    for(int i=1; i<=n; i++)

        if(disc[i]==-1)

            mom=0, Tarjan(i);



    out<<componente.size()<<"\n";

    for(auto & vec: componente)

    {

        for(auto & x : vec)

            out<<x<<" ";

        out<<"\n";

    }



    return 0;

}
