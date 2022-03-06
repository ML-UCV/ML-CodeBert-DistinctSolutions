#include <fstream>
#include <vector>
#include <list>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



int n, m;

int comp[100001];

bool vis[100001];



list < int > L;



vector < int > inNeighbour[100001];

vector < int > outNeighbour[100001];



int nrComp;

vector < vector < int > > components;



void visit(int node)

{

    if (vis[node])

        return;



    vis[node] = true;



    for (auto it : outNeighbour[node])

        if (!vis[it])

            visit(it);



    L.push_back(node);

}



void assignComponent(int node, int c)

{

    if (comp[node])

        return;



    comp[node] = c;



    components.back().push_back(node);



    for (auto it : inNeighbour[node])

        if (!comp[it])

            assignComponent(it, c);

}



int main()

{

    f >> n >> m;

    for (int i=1; i<=m; i++)

    {

        int x, y; f >> x >> y;

        outNeighbour[x].push_back(y);

        inNeighbour[y].push_back(x);

    }



    for (int i=1; i<=n; i++)

        if (!vis[i])

            visit(i);



    for (list < int > :: iterator it = L.end(); it != L.begin();)

    {

        it--;

        if (!comp[*it])

        {

            nrComp++;

            components.resize(nrComp);

            assignComponent(*it, nrComp);

        }

    }



    g << nrComp << "\n";

    for (int i=0; i<nrComp; i++)

    {

        for (auto it : components[i])

            g << it << " ";

        g << "\n";

    }



    return 0;

}
