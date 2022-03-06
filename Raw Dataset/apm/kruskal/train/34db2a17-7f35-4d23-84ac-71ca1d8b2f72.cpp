#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



struct edge

{

    int node1, node2;

    int cost;

};



bool cmp(edge a, edge b)

{

    return a.cost < b.cost;

}



int n, m;



vector < edge > e;

vector < int > sol;

vector < int > parent, h;



void uneste(int x, int y)

{

    while (parent[x])

        x = parent[x];



    while (parent[y])

        y = parent[y];



    if (x == y)

        return;



    if (h[x] <= h[y])

    {

        parent[x] = y;

        h[y] = max(h[y], h[x] + 1);

    }

    else

    {

        parent[y] = x;

        h[x] = max(h[x], h[y] + 1);

    }

}





bool verif(int x, int y)

{

    int m1 = x, m2 = y;



    while (parent[m1])

        m1 = parent[m1];



    while (parent[m2])

        m2 = parent[m2];



    int aux;



    while (parent[x])

    {

        aux = x;

        x = parent[x];

        parent[aux] = m1;

    }



    while (parent[y])

    {

        aux = y;

        y = parent[y];

        parent[aux] = m2;

    }



    return m1 != m2;

}



int main()

{

    f >> n >> m;



    e.resize(m);

    h.resize(n + 1);

    parent.resize(n + 1);



    for (int i=0; i<m; i++)

        f >> e[i].node1 >> e[i].node2 >> e[i].cost;



    sort(e.begin(), e.end(), cmp);



    int costTotal = 0;

    for (int i=0; i<m; i++)

        if (verif(e[i].node1, e[i].node2))

        {

            uneste(e[i].node1, e[i].node2);

            costTotal += e[i].cost;



            sol.push_back(i);

            if (sol.size() == n - 1)

                break;

        }



    g << costTotal << "\n";

    g << sol.size() << "\n";

    for (auto it : sol)

        g << e[it].node1 << " " << e[it].node2 << "\n";



    return 0;

}
